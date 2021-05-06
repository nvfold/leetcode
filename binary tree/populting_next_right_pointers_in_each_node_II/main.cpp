#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root){
    if(root == NULL) return NULL;

    root->next = NULL;
    Node* father = root;

    while(father){

        Node* childs_level_start = NULL;
        // find first child / level start
        while(father){
            if(father->left){
                childs_level_start = father->left;
                break;
            }
            if(father->right){
                childs_level_start = father->right;
                break;
            }

            father = father->next;
        }

        // connect child
        Node* c1 = childs_level_start;
        while(c1){
            // c1->next = c2;
            // c2 = ?
            Node* c2 = NULL;

            while(father){
                if(father->left && father->left != c1){
                    c2 = father->left;
                    break;
                }
                if(father->right && father->right != c1){
                    c2 = father->right;
                    father = father->next;
                    break;
                }

                father = father->next;
            }

            c1->next = c2;
            c1 = c1->next;
        }

        // all children are connected
        father = childs_level_start;
    }
    return root;
}
int main() {
    Node* root = new Node{1};
    root->left = new Node{3};
    root->right = new Node{2};
    root = connect(root);
    return 0;
}
