/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        while(head != NULL){
            ListNode* prev = NULL;
            ListNode* cur = head->next;

            while (cur != NULL) {

                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;

            }
            head->next = prev;
            head = head->next;
        }

        return ;
    }
};