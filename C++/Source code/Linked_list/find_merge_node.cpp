// Tự viết
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

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }
        this->tail = node;
    }
    void printLinkedList() {
        SinglyLinkedListNode* p;
        p = head;
        while (p != NULL){
            cout<<p->data<<endl;
            p = p->next;
        }
    }

};

// Complete the SinglyLinkedListNode* findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) function below.
/*
	 * For your reference:
	 *
	 * SinglyLinkedListNode {
	 *     int data;
	 *     SinglyLinkedListNode* next;
	 * };
	 * SinglyLinkedList {
     *    SinglyLinkedListNode *head;
     *    SinglyLinkedListNode *tail;
	 *
	 */
SinglyLinkedListNode* findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//    SinglyLinkedListNode *ptr = head2;
//    cout << "Gia tri list 2: ";
//    while (ptr != nullptr) {
//        cout << ptr->data << ' ';
//        ptr = ptr->next;
//    }
//    cout << endl;

    if (head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }

    SinglyLinkedListNode *pHead1 = head1, *pHead2 = head2;
    int count1 = 0, count2 = 0;

    while (pHead1) {
        count1++;

        pHead1 = pHead1->next;
    }

    while (pHead2) {
        count2++;

        pHead2 = pHead2->next;
    }

//    cout << "Count : " << count1 << " - " << count2 << endl;

    pHead1 = head1;
    pHead2 = head2;

    if (count1 > count2) {
//        cout << "Loai 1: ";
        while (count1 > count2) {
//            cout << pHead1->data << ' ';
            count1--;
            pHead1 = pHead1->next;
        }
//        cout << endl;
    } else if (count1 < count2) {
//        cout << "Loai 2: ";
        while (count1 < count2) {
//            cout << pHead2->data << ' ';
            count2--;
            pHead2 = pHead2->next;
        }
//        cout << endl;
    }

    while (count1--) {
        if (pHead1 == pHead2) {
            return pHead1;
        }

//        cout << "Xet cac value: " << pHead1->data << " - " << pHead2->data << endl;

        pHead1 = pHead1->next;
        pHead2 = pHead2->next;
    }

    return nullptr;
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}



int main()
{
    SinglyLinkedList* llist1 = new SinglyLinkedList();
    SinglyLinkedList* llist2 = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist1->insert_node(llist_item);
    }

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist2->insert_node(llist_item);
    }

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (llist_count>0){
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist1->insert_node(llist_item);
        if (llist2->head != nullptr)  llist2->tail->next = llist1->tail;
        else llist2->head = llist2->tail = llist1->tail;
    }
    for (int i = 1; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        llist1->insert_node(llist_item);
    }
    llist2->tail = llist1->tail;

    SinglyLinkedListNode* p;
    p = findMergeNode(llist1->head,llist2->head);
    if (p == nullptr)
        cout<<"NA";
    else
        cout<<p->data;

    //free_singly_linked_list(llist1->head);
    //free_singly_linked_list(llist2->head);

    return 0;
}

/*
Test 1:
5
1
2
3
4
5
3
1
2
3
2
6
7

=> 6

Test 2:
5
1
42
5
4
2
0
2
19
43

=> 19
*/