#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;
using ll = long long;


// installing the singly linked-list
template <typename T>
struct Node {
    T data;
    Node* nodeNext;
};
template <typename DATA>
Node <DATA>* makeNode (DATA Data) {
    Node <DATA>* newNode = new Node <DATA>;
    newNode -> data = Data;
    newNode -> nodeNext = NULL;
    return newNode;
}

template <typename DATA>
void print (Node <DATA>* root) {
    while (root != NULL) {
        std::cout << "[" << root -> data << " | " << root << "] -> ";
        root = root -> nodeNext;
    }
    if (root == NULL) std::cout << "NULL";
}

template <typename DATA>
int countNode (Node <DATA>* root) {
    int count = 0;
    while (root != NULL) {
        ++count;
        root = root -> nodeNext;
    }
    return count;
}

template <typename DATA>
void pushFront (Node <DATA> *&root, DATA value) {
    Node <DATA>* tmp = makeNode <DATA> (value);
    tmp -> nodeNext = root;
    root = tmp;
}

template <typename DATA>
void pushBack (Node <DATA> *&root, DATA value) {
    Node <DATA>* newNode = makeNode <DATA> (value);
    Node <DATA>* tmp = root;
    if (root == NULL) {
        root = newNode;
        return;
    }
    while (tmp -> nodeNext != NULL) {
        tmp = tmp -> nodeNext;
    }
    tmp -> nodeNext = newNode;
}

template <typename DATA>
void popFront (Node <DATA> *&root) {
    if (root == NULL) return;
    Node <DATA> *tmp = root;
    root = root -> nodeNext;
    delete tmp;
    tmp = NULL;
}

template <typename DATA>
void popBack (Node <DATA> *&root) {
    if (root == NULL) return;
    Node <DATA>* tmp = root;
    if (tmp -> nodeNext == NULL) {
        root = NULL;
        delete tmp;
        tmp = NULL;
        return;
    }
    while (tmp -> nodeNext -> nodeNext != NULL) {
        tmp = tmp -> nodeNext;
    }
    Node <DATA>* nodeLast = tmp -> nodeNext;
    delete nodeLast;
    nodeLast = NULL;
    tmp -> nodeNext = NULL;                    
}

template <typename T>
class Stack{

    private:
        Node <T> *root = NULL;

    public:
        // constructor
        Stack (): root(NULL) {}
        Stack (std::vector <T> Data) {for ( T i : Data) pushFront(root, i);}
        Stack (Stack* newStack): root (newStack) {} 

        // methods
        void pop () {
            popFront (root);
        }
        void push (T data) {
            pushFront (root, data);
        }
        T top () {
            return root -> data;
        }
        int size () {
            return countNode (root);
        }
        bool empty () {
            if (root == NULL) return true;
            else return false;
        }

        // destructor
        ~Stack () {
            if (root -> nodeNext == NULL) delete root;
            Node <T>* tmp = root;
            while (tmp -> nodeNext != NULL) {
                Node <T>* secondTmp = tmp;
                tmp = tmp -> nodeNext;
                delete secondTmp;
            }
        }
};


template <typename N>
class Queue {

    private:
        Node <N>* root = NULL;
    
    public:
        // constructo
        Queue (): root (NULL) {}
        Queue (std::vector <N> data) {for (N i : data) pushBack (root, i);}
        Queue (Queue* tmp) : root (tmp) {}

        // methods
        void push (N data) {
            pushBack (root, data);
        }// enqueue

        void pop () {
            popFront (root);
        } // dequeue

        N front () {
            return root -> data;
        }

        N back () {
            Node <N>* tmp = root;
            while (tmp -> nodeNext != NULL) {
                tmp = tmp -> nodeNext;
            }
            return tmp -> data;
        }

        int size () {
            return countNode (root);
        }

        bool empty () {
            if (root == NULL) return true;
            else return false;
        }
};

void analysPrimeNumber (int number) {
    Stack <int>* primeNumber = new Stack <int>;
    for (int i = 2; i <= number; ++i) {
        while (number % i == 0) {
            primeNumber -> push (i);
            number /= i;
        }
    }

    while (!primeNumber -> empty ()) {
        std::cout << primeNumber -> top () << " ";
        primeNumber -> pop ();
    }
}

void demiToHexa (int n) {
    Stack <char>* convertContainer = new Stack <char>;
    std::vector <char> convert =  {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n) {
        int m = n % 16;
        convertContainer -> push (convert[m-1]);
        n /= 16;
    }

    while (!convertContainer -> empty()) {
        std::cout << convertContainer -> top ();
        convertContainer -> pop ();
    }
}

void demiToOct (int n) {
    Stack <int>* container = new Stack <int>;
    while (n) {
        container -> push (n%8);
        n /= 8;
    }

    while (!container -> empty ()) {
        std::cout << container -> top ();
        container -> pop ();
    }
}

void demiToBin (int n) {
    Stack <int>* container = new Stack <int>;
     while (n) {
        container -> push (n%2);
        n /= 2;
    }

    while (!container -> empty ()) {
        std::cout << container -> top ();
        container -> pop ();
    }
}
int main(){

    // testing stack
    Stack <int>* s = new Stack <int> ({1, 2, 6, 7,10});
    s -> push (10);
    std::cout << s -> top () << '\n';
    std::cout << s -> size () << '\n';
    s -> pop ();
    while (!s -> empty ()){
        std::cout << s -> top () << " ";
        s -> pop ();
    }
    std::cout << '\n';
    
    
    // action on number
    analysPrimeNumber (1000);
    std::cout << '\n';
    demiToHexa (199);
    std::cout << '\n';
    demiToOct (199);
    std::cout << '\n';
    demiToBin (199);
    std::cout << '\n';
     
     // testing queue
     Queue <int>* q = new Queue <int> ({1,2,3,4,5,6,7});
     std::cout << q -> front () << '\n';
     std::cout << q -> back ()  << '\n';
     std::cout << q ->size () << '\n';
     q -> pop ();
     q -> push (100);
     while (!q -> empty()){
        std::cout << q -> front () << " ";
        q -> pop ();
     }
    return 0;
}
