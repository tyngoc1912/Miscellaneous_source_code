#include <bits/stdc++.h>
using namespace std;
	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }  

    // traverse the tree using recursion
    // NLR
    void preOrder(Node *root) {
        if (root != NULL) {
            std::cout << root -> data <<  " ";
            preOrder (root -> left);
            preOrder (root -> right);
        }
    }

    // LRN
    void postOrder (Node* root){
        if (root != NULL) {
            postOrder (root -> left);
            postOrder (root -> right);
            std::cout << root -> data <<  " ";
        }
    }

    // LNR
    void inOrder (Node* root) {
        if (root != NULL){
            inOrder (root -> left);
            std::cout << root -> data << " ";
            inOrder (root -> right);
        }
    }

    // traverse without recursion
    // NLR
    void preOrderWithStack (Node* root) {
        if (root == NULL) return;
        std::stack <Node*> nodeList;
        nodeList.push (root);
        Node* current;
        while (!nodeList.empty()){
            current = nodeList.top ();
            std::cout << current -> data << " ";
            nodeList.pop ();
            if (current -> right != NULL) nodeList.push (current -> right);
            if (current -> left != NULL) nodeList.push (current -> left);
        }
    }
    // LRN
    void postOrderWithStack (Node* root) {
        if (root == NULL) return;

        stack<Node*> s1, s2;
        s1.push(root);
        Node* node;

        while (!s1.empty()) {
           node = s1.top();
           s1.pop();
           s2.push(node);

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        while (!s2.empty()) {
            node = s2.top();
            s2.pop();
            std::cout << node->data << " ";
        }
    }
    // LNR
    void inOrderWithStack(Node* root) {
        stack<Node*> s;
        Node* curr = root;
        while (curr != NULL || s.empty() == false) {
            while (curr !=  NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            std::cout << curr->data << " ";
            curr = curr->right;
        }
    }


    // traverse without stack and recursion
    // NLR
    void preOrderWithoutStack(Node* root) {
        while (root) {
            if (root->left == NULL) {
                std::cout << root->data << " ";
                root = root->right;
            } else {
                Node* node = root->left;
                while (node->right != NULL && node->right != root) {
                   node = node->right;
                }

                if (node->right == root) {
                    node->right = NULL;
                   root = root->right;
                } else {
                    std::cout << root->data << " ";
                    node->right = root;
                    root = root->left;
                }
            }
        }
    }

    // LRN not available here beacause it cost too much

    // LNR
    void inorder_traversal(Node* root) {
        Node *curr, *pre;

        if (root == NULL)
            return;

        curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                std::cout << curr->data << " ";
                curr = curr->right;
            } else {
                pre = curr->left;
                while (pre->right != NULL && pre->right != curr)
                    pre = pre->right;

                if (pre->right == NULL) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    std::cout << curr->data << " ";
                    curr = curr->right;
                }
            }
        }
    }


    // traverse follow level order
    void levelOrder (Node* root){
        std::queue <Node*> queueList;
        queueList.push (root);
        std::cout << root -> data << " ";
        while (!queueList.empty()){
            Node* current = queueList.front ();
            queueList.pop();
            if (current -> left != NULL) {
                queueList.push (current -> left);
                std::cout << current -> left -> data <<  " ";
            }
            if (current -> right != NULL){
                queueList.push (current -> right);
                std::cout << current -> right -> data << " ";
            }
        }
    }

    // Height
    int height (Node* root){
        if (root == NULL) return 0;
        int leftHeight = height (root-> left);
        int rightHeight = height (root -> right);
        return leftHeight > rightHeight ? leftHeight + 1: rightHeight + 1;
    }

    //BST
    Node* insert (Node* root, int data) {
        Node* newNode = new Node (data);
        if (root == NULL) return newNode;
        if (data < root -> data) {
            root -> left = insert (root -> left, data);
        }else if (data > root -> data) {
            root -> right = insert (root -> right, data);
        }
        return root;
    }
    
};

int main() {
    
    Solution myTree;
    Node* root = NULL;

    vector <int> data = {1, 2,5,3,4,6};

    for (int i : data) root = myTree.insert (root, i);

    return 0;
}