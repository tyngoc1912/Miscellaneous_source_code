//Binary_tree
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
/*  You only have to complete the function given below.  
    Node is defined as  

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
*/

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

    void preOrder(Node *root) {
        if( root == NULL ) return;
      
        std::cout << root->data << " ";
        
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node *root) {

    }

    void postOrder(Node *root) {

    }

    void levelOrder(Node *root) {

    }

    int height(Node* root) {

    }
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    myTree.inOrder(root);

    myTree.postOrder(root);

    myTree.levelOrder(root);

    int height = myTree.height(root);
    std::cout << height;

    return 0;
}