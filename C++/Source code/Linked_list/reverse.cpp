//Viết sẵn
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
    
};

//Implementation


int main(){
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}

//Tự viết
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

};

void insert_node(SinglyLinkedList *myList, int &data) {
    SinglyLinkedListNode *myElement = new SinglyLinkedListNode(data);

    if (myList->head == nullptr) {
        myList->head = myElement;
    } else {
        myList->tail->next = myElement;
    }

    myList->tail = myElement;
}

void printLinkedList(SinglyLinkedList *myList) {
    SinglyLinkedListNode *tail = myList->tail;

    while (tail) {
        cout << tail->data << ' ';

        tail = tail->next;
    }
}

void reverseLinkedList(SinglyLinkedList *myList) {
    SinglyLinkedListNode *prev = nullptr, *next = nullptr;
    SinglyLinkedListNode *current = myList->head;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */


int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }


    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
