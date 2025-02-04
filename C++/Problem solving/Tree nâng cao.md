# Cây nâng cao
## B-Tree
```cpp
struct Node{
    vector<int> keys;
    vector<Node*> children;
    vector<int> path;
    int t;
    bool leaf(){return children.empty();}
    Node(int t) : t(t){}

    //Duyệt node
    void traverseNode(vector<int> &path){
        int i;
        for(i = 0; i < keys.size(); i++){
            if(!leaf()) children[i]->traverseNode(path);
            //cout << keys[i] << ", ";
            path.push_back(keys[i]);
        }
        if(!leaf()) children[i]->traverseNode(path);  
    }

    //Tìm kiếm node
    bool searchNode(int k){
        int i = 0;
        while(i < keys.size() && k > keys[i]) i++;
        if(i < keys.size() && keys[i] == k) return true;
        if(leaf()) return false;
        return children[i]->searchNode(k);
    }

    //Chèn node
    void splitChild(int i, Node* y){
        Node* z = new Node(y->t);
        z->keys.resize(t - 1);
        for(int j = 0; j < t - 1; j++){
            z->keys[j] = y->keys[j + t];
        }
        if(!y->leaf()){
            z->children.resize(t);
            for(int j = 0; j < t; j++){
                z->children[j] = y->children[j + t];  
            } 
        }
        y->keys.resize(t - 1);
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }
    void insertNode(int k){
        int i = keys.size() - 1;
        if(leaf()){
            keys.push_back(0);
            while(i >= 0 && keys[i] > k){
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
        } 
        else{
            while(i >= 0 && keys[i] > k) i--;
            if (children[i + 1]->keys.size() == 2 * t - 1){
                splitChild(i + 1, children[i + 1]);
                if(keys[i + 1] < k) i++;
            }
            children[i + 1]->insertNode(k);
        }
    }
    //Xóa node
    void merge(int i) {
        Node* child = children[i];
        Node* sib = children[i + 1];

        child->keys.push_back(keys[i]);
        child->keys.insert(child->keys.end(), sib->keys.begin(), sib->keys.end());

        if(!child->leaf()){
            child->children.insert(child->children.end(), sib->children.begin(), sib->children.end());
        }

        keys.erase(keys.begin() + i);
        children.erase(children.begin() + i + 1);

        delete sib;
    }

    void fill(int i){
        if(i != 0 && children[i - 1]->keys.size() >= t){
            Node* child1 = children[i];
            Node* sib1 = children[i - 1];

            child1->keys.insert(child1->keys.begin(), keys[i - 1]);

            if (!child1->leaf()){
                child1->children.insert(child1->children.begin(), sib1->children.back());
            }

            keys[i - 1] = sib1->keys.back();
            sib1->keys.pop_back();

            if (!sib1->leaf()){
                sib1->children.pop_back();
            }
        } 
        else if(i != keys.size() && children[i + 1]->keys.size() >= t){
            Node* child2 = children[i];
            Node* sib2 = children[i + 1];

            child2->keys.push_back(keys[i]);

            if(!child2->leaf()){
                child2->children.push_back(sib2->children[0]);
            }

            keys[i] = sib2->keys[0];
            sib2->keys.erase(sib2->keys.begin());
            
            if(!sib2->leaf()){
                sib2->children.erase(sib2->children.begin());
            }
        } 
        else{
            if(i != keys.size()) merge(i);
            else merge(i - 1);
        }
    }
    void removeNode(int k) {
        int i = 0;
        while(i < keys.size() && keys[i] < k) ++i;

        if(i < keys.size() && keys[i] == k){
            if(leaf()){
                keys.erase(keys.begin() + i);
            }
            else{
                int k = keys[i];
                if(children[i]->keys.size() >= t){
                    //find predecessor
                    Node* find1 = children[i];
                    while(!find1->leaf()){
                        find1 = find1->children[find1->keys.size()];
                    }
                    int pred = find1->keys[find1->keys.size() - 1];
                    keys[i] = pred;
                    children[i]->removeNode(pred);
                }
                else if(children[i + 1]->keys.size() >= t){
                    //find successors
                    Node* find2 = children[i + 1];
                    while(!find2->leaf()){
                        find2 = find2->children[0];
                    }
                    int succ = find2->keys[0];
                    keys[i] = succ;
                    children[i + 1]->removeNode(succ);
                }
                else{
                    merge(i);
                    children[i]->removeNode(k);
                }
            }
        }
        else{
            if(leaf()) return;
            bool check = (i == keys.size());
            if(children[i]->keys.size() < t){
                fill(i);
            }
            if(check && i > keys.size()){
                children[i - 1]->removeNode(k);
            }
            else children[i]->removeNode(k);
        }
    }

};

struct BTree{
    Node* root;
    int t;
    BTree(int t) : t(t), root(NULL){}
    //duyệt cây
    void traverse(){
        if(root != NULL) root->traverseNode(root->path); 
    }
    void print(){
        for(auto x : root->path){
            if(x != root->path.back()) cout << x << ", ";
            else cout << x;
        }
        root->path.clear();
    }
    //tìm kiếm node trên cây
    bool search(int k){ 
        return root->searchNode(k); 
    }
    //Chèn node vào cây
    void insert(int k){
        if(!root){
            root = new Node(t);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                Node* s = new Node(t);
                s->children.push_back(root);
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k) i++;
                s->children[i]->insertNode(k);
                root = s;
            } else {
                root->insertNode(k);
            }
        }
    }
    //Xóa node trên cây
    void remove(int k){
        if(!root) return;
        root->removeNode(k);
        if (root->keys.size() == 0) {
            Node* tmp = root;
            if (root->leaf()) root = nullptr;
            else root = root->children[0];
            delete tmp;
        }
    }

};
// Test
int main(){
    BTree t(3); // A B-Tree with minimum degree 3

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    t.traverse(); t.print(); 
    cout << endl;

    t.remove(6);
    t.traverse(); t.print();
    cout << endl;

    t.remove(7);
    t.traverse(); t.print();
    cout << endl;

    t.remove(30);
    t.traverse(); t.print();
    cout << endl;
		
		cout << t.search(17) << endl;
    cout << t.search(6) << endl;
}
```
Hàm thêm chưa test :
```cpp
//Btree
const int max_val = 4;
struct node{
    node* root;
    vector<int> key; // mỗi root là vector chứa tối thiểu m key và tối đa 2m key
    vector<node*> child;
    //int max_val; // giá trị tối đa mà key được chứa ở mỗi node
    //constructor
    node(){root = NULL;}
    // node(int m){
    //     if(m % 2 == 0) this->max_val = m / 2 + 1;
    //     root = NULL;
    // }
    //basic fuction
    bool isLeaf(){
        return child.empty();
    }
    bool empty(){ //cây rỗng hay ko
        return root == NULL;
    }
};

pair<int, vector<node*>> search(node* root, int k){
    vector<node*> path;
    while(root != NULL){
        path.push_back(root);
        auto i = lower_bound(root->key.begin(), root->key.end(), k);
        if(i != root->key.end() && *i == k) return {i - root->key.begin(), path};
        else{
            if(root->isLeaf()) break;
            root = root->child[i - root->key.begin()];
        }
    }
    return {-1, path};
}

node* splitNode(node* x, node* p){ //split node x có cha là p
    if(x->key.size() < max_val) return NULL;
    auto newNode = new node;
    auto moveNode = x->key[x->key.size()/2];
    //move nửa giá trị sau của node x vào newNode
    move(x->key.begin() + x->key.size() / 2 + 1, x->key.end(), back_inserter(newNode->key));
    if(!x->isLeaf()){
        //move 1 nửa số con của node x sang newNode
        move(x->child.begin() + x->key.size() / 2 + 1, x->child.end(), back_inserter(newNode->child));
        x->child.resize(x->key.size() / 2 + 1);
    }
    x->key.resize(x->key.size() / 2);
    if(p == NULL) p->child.push_back(x);
    //tìm chỉ số cần chèn khóa ở node cha
    int ip = lower_bound(p->key.begin(), p->key.end(), moveNode) - p->key.begin();
    p->key.insert(p->key.begin() + ip, moveNode);
    p->child.insert(p->child.begin() + ip + 1, newNode);
    return p;
}

node* split(vector<node*> &path){
    vector<node*>::iterator x = path.end() - 1;
    while(x != path.begin() - 1){
        vector<node*>::iterator p = x - 1;
        if(x == path.begin()){
            node* i = splitNode(*x, NULL);
            if(i == NULL) return path.front();
            else return i;
        }
        else{
            node* i = splitNode(*x, *p);
            if(i == NULL) return path.front();
            else{
                i = *p; // move up the path 
            } 
        }
    }
    return path.front();
}
```

## Red-Black Tree
```cpp
// Node structure for the Red-Black Tree
struct Node {
    int data;
    string color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color("RED"), left(NULL), right(NULL), parent(NULL){}
};

// Red-Black Tree class
struct RedBlackTree{
    Node* root;
    Node* leaf;

    // Constructor
    RedBlackTree(){
        leaf = new Node(0);
        leaf->color = "BLACK";
        leaf->left = leaf->right = leaf;
        root = leaf;
    }

    // Inorder function -> can use other traverse function in BST
    void inorder(Node* node){
        if(node != leaf){
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    //traversal
    void traverse(){ 
        inorder(root); 
    }

    // Search function
    Node* search(Node* node, int data){
        if(node == leaf || data == node->data) return node;
        if(data < node->data){
            return search(node->left, data);
        }
        return search(node->right, data);
    }
    //find node in RedBlackTree
    Node* find(int data){
        return search(root, data);
    }

    //Insert
    // left rotation
    void leftRotate(Node* x){
        Node* y = x->right;
        x->right = y->left;

        if(y->left != leaf) y->left->parent = x;
        y->parent = x->parent;

        if(x->parent == NULL) root = y;
        else if(x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;
    }
    //right rotation
    void rightRotate(Node* x){
        Node* y = x->left;
        x->left = y->right;

        if(y->right != leaf) y->right->parent = x;
        y->parent = x->parent;

        if(x->parent == NULL) root = y;
        else if(x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        
        y->right = x;
        x->parent = y;
    }
    //fix Red-Black Tree properties after insertion
    void fixInsert(Node* k){
        while(k != root && k->parent->color == "RED"){
            if(k->parent == k->parent->parent->left){
                Node* u = k->parent->parent->right; // uncle
                if(u->color == "RED"){
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else{
                    if(k == k->parent->right){
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    rightRotate(k->parent->parent);
                }
            }
            else{
                Node* u = k->parent->parent->left; // uncle
                if(u->color == "RED"){
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else{
                    if(k == k->parent->left){
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    leftRotate(k->parent->parent);
                }
            }
        }
        root->color = "BLACK";
    }
    // Insert function
    void insert(int data){
        Node* x = new Node(data);
        x->left = leaf;
        x->right = leaf;

        Node* p = NULL;
        Node* tmp = root;

        // BST insert
        while(tmp != leaf){
            p = tmp;
            if(x->data < tmp->data) tmp = tmp->left;
            else tmp = tmp->right;
        }
        x->parent = p;

        if(p == NULL) root = x;
        else if(x->data < p->data) p->left = x;
        else p->right = x;

        if(x->parent == NULL){
            x->color = "BLACK";
            return;
        }
        if(x->parent->parent == NULL) return;

        fixInsert(x);
    }
};

int main(){    
    RedBlackTree rbt;

    // Inserting elements
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(3);

    // Inorder traversal
    cout << "Inorder traversal:" << endl;
    rbt.traverse(); // Output: 10 15 20 30

    // Search for a node
    cout << "\nSearch for 15: "
         << (rbt.find(15) != rbt.find(0))
         << endl; // Output: 1 (true)
    cout << "Search for 25: "
         << (rbt.find(20) != rbt.find(0))
         << endl; // Output: 0 (false)
}
```