//Node
struct Node{
    int data;
    Node* next;
};

Node* initNode(int value){
    Node* p = new Node();
    p->data = value;
    p->next = NULL;
    return p;
}

// Linked list
struct LinkedList{
    Node* head;
    Node* tail;
};

void initList(LinkedList& l){
    l.head = NULL;
    l.tail = NULL;
}

void addHead(LinkedList& l, Node* p){
    if(l.tail == NULL) l.head = l.tail = p;
    else{
        p->next = l.head;
        l.head = p;
    }
}

void addTail(LinkedList& l, Node* p){
    if(l.head == NULL) l.head = l.tail = p;
    else{
        l.tail->next = p;
        l.tail = p;
    }
}

void insertAfterQ(LinkedList& l, Node* p, Node* q){
    if(q != NULL){
        p->next = q->next;
        q->next = p;
        if(l.tail == q) l.tail = p;
    }
    else addHead(l, p);
}

void printList(LinkedList l){
    Node* p = l.head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

bool search(LinkedList l, int value){
    if(l.head == NULL) return false;
    for(Node* i = l.head; i != NULL; i = i->next){
        if(i->data == value) return true;
    }
    return false;
}
Node* searchNearLast(LinkedList l){
    Node* p = l.head;
    if(p == NULL) return NULL;
    while(p->next != l.tail) p = p->next;
    return p;
}

void removeHead(LinkedList& l){
    if(l.head == NULL) return;
    else{
        Node* p = l.head;
        l.head = l.head->next;
        delete p;
        if(l.head == NULL) l.tail == NULL;
    }
}

void removeTail(LinkedList& l){
    if(l.head == NULL) return;
    if(l.head == l.tail){
        delete l.tail;
        l.head = l.tail = NULL;
    }
    else{
        Node* p = l.head;
        while(p->next != l.tail){
            p = p->next;
        }
        Node* d = l.tail;
        l.tail = p;
        l.tail->next = NULL;
        delete d;
    }
}

void removeAfterQ(LinkedList& l, Node* q){
    Node* p;
    if(q != NULL){
        p = q->next;
        if(p != NULL){
            if(p == l.tail) l.tail = q;
            q->next = p->next;
            delete p;
        }
    }
}

void removeX(LinkedList& l, int x){
    Node* p = l.head, *q = NULL;
    while((p != NULL) && (p->data != x)){
        q = p;
        p = p->next;
    }
    if(p == NULL) return;
    if(q != NULL) removeAfterQ(l, q);
    else removeHead(l);
}

void removeLinkedList(LinkedList& l){
    Node* p;
    while(l.head != NULL){
        p = l.head;
        l.head = l.head->next;
        delete p;
    }
}

void selectionSort(LinkedList& l){
    for(Node* p = l.head; p != l.tail; p = p->next){
        Node* min = p;
        for(Node* q = p->next; q != l.tail; q = q->next){
            if(min->data > q->data) min = q;
        }
        swap(min->data, p->data);
    }
}

// Stack
struct Stack{
    Node* top;
};

void initStack(Stack& st){
    st.top = NULL;
}

void push(Stack& st, Node* p){
    if(st.top == NULL) st.top = p;
    else{
        p->next = st.top;
        st.top = p;
    }
}

void pop(Stack& st){
    if(st.top == NULL) return;
    else{
        Node* p = st.top;
        st.top = st.top->next;
        delete p;
    }
}

void printStack(Stack st){
    for(Node* p = st.top; p != NULL; p = p->next){
        cout << p->data << " ";
    }
    cout << endl;
}

Node* getTop(Stack st){
    return st.top;
}

int getSize(Stack st){
    Node* p = st.top;
    int cnt = 0;
    while(p != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

//Hàng đợi
struct Queue{
    Node* front;
    Node* rear;
};

void initQueue(Queue& q){
    q.front = NULL;
    q.rear = NULL;
}

void deQueue(Queue& q){
    if(q.front == NULL) return;
    else{
        Node* p = q.front;
        q.front = q.front->next;
        delete p;
    }
}

void enQueue(Queue& q, Node* p){
    if(q.front == NULL) q.front = q.rear = p;
    else{
        q.rear->next = p;
        q.rear = p;
    } 
}

void printQueue(Queue q){
    for(Node* p = q.front; p != NULL; p = p->next){
        cout << p->data << " ";
    }
    cout << endl;
}

Node* getFront(Queue q){
    return q.front;
}

int getSize(Queue q){
    Node* p = q.front;
    int cnt = 0;
    while(p != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

// Hash table
#define size 10

struct Bucket{
    Node* head;
    Node* tail;
};

void initBucket(Bucket& b){
    b.head = b.tail = NULL;
}

void addBucket(Bucket& b, Node* p){
    if(b.tail == NULL){
        b.head = b.tail = p;
    }
    else{
        b.tail->next = p;
        b.tail = p;
    }
}

void printBucket(Bucket b){
    for(Node* p = b.head; p != NULL; p = p->next){
        cout << p->data << " ";
    }
    cout << endl;
}

struct HashTable{
    Bucket bucket[size];
};

void initHashTable(HashTable& ht){
    for(int i = 0; i < size; i++){
        initBucket(ht.bucket[i]);
    }
}

int hashFunction(int value){
    return abs(value) % size;
}

void add(HashTable& ht, Node* p){
    int pos = hashFunction(p->data);
    addBucket(ht.bucket[pos], p);
}

void printHashTable(HashTable ht){
    for(int i = 0; i < size; i++){
        printBucket(ht.bucket[i]);
    }
}