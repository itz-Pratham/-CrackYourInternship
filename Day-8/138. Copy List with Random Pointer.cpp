/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // cloning nodes
        Node* cur = head;
        while (cur) {
            Node* temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }

        // setting random pointers
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // separating the lists 
        cur = head;
        Node* newHead = head->next;
        Node* copy = newHead;
        while (cur) {
            cur->next = cur->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            cur = cur->next;
            copy = copy->next;
        }

        return newHead;
    }

};