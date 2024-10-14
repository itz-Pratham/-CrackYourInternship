/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        if(ptr1 == NULL || ptr2 == NULL){
            return NULL;
        }
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2){
                return ptr1;
            }
            if(ptr1 == NULL){
                ptr1 = l2;
            }
            if(ptr2 == NULL){
                ptr2 = l1;
            }
        }
        return ptr1;
    }
};