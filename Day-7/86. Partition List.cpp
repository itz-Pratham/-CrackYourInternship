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
    ListNode* partition(ListNode* head, int x) {

        ListNode* cur = head;
        ListNode* dummy_low = new ListNode(0);
        ListNode* less_tail = dummy_low;
        ListNode* dummy_high = new ListNode(0);
        ListNode* great_tail = dummy_high;
        while(cur!=NULL)
        {
            if(cur->val<x){
                less_tail->next = cur;
                less_tail = cur;
            }
            else{
                great_tail->next = cur;
                great_tail = cur;
            }
            cur = cur->next;
        }
        great_tail->next = NULL;

        less_tail->next = dummy_high->next;

        return dummy_low->next;

       
    }
};