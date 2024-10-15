// The idea is to traverse the linked List and count the number of nodes having values 0, 1 and 2 and store them in an array of size 3, say cnt[] such that


// cnt[0] = count of nodes with value 0
// cnt[1] = count of nodes with value 1 
// cnt[2] = count of nodes with value 2
// Now, traverse the linked list again to fill the first cnt[0] nodes with 0, then next cnt[1] nodes with 1 and finally cnt[2] nodes with 2.

class Solution{
    public:
    void sortList(Node* head) {

        int cnt[3] = {0, 0, 0};
        Node *ptr = head;
        while (ptr != NULL) {
            cnt[ptr->data] += 1;
            ptr = ptr->next;
        }

        int idx = 0;
        ptr = head;

        while (ptr != nullptr) {

            if (cnt[idx] == 0)
                idx += 1;
            else {
                ptr->data = idx;
                cnt[idx] -= 1;
                ptr = ptr->next;
            }
        }
    }
};