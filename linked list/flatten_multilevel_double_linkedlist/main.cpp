#include <iostream>
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
struct Node{
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// flatten a list
// return head and tail of this list after flatten
void flattenHelper(Node* const &head, Node* &tail){
    Node* curr = head;
    do{
        // con trỏ tail chạy riêng
        tail = (curr->next)?curr->next:tail;

        Node* currNext = curr->next;

        if(curr->child){
            // curr hat child
            // flatten child list
            Node* cHead = curr->child, *cTail = curr->child;
            flattenHelper(cHead,cTail);

            // insert child list in between curr and currNext
            curr->next = cHead;
            cHead->prev = curr;
            cTail->next = currNext;
            if(currNext)
                currNext->prev = cTail;
            else
                tail = cTail;
            curr->child = nullptr;
        }

        // chạy curr tới nốt kế tiếp trong list ban đầu
        curr = currNext;
    }while(curr);
}

Node* flatten(Node* &head) {
    if(!head) return head;

    Node* tail = head;
    flattenHelper(head, tail);
    return head;
}

int main() {
    Node* head = new Node{1, nullptr, nullptr, nullptr};
    head->child = new Node{2, nullptr, nullptr, nullptr};
    head->child->child = new Node{3, nullptr, nullptr, nullptr};
    flatten(head);
    return 0;
}
