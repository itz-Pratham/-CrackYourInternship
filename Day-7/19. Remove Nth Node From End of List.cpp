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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int count = 1;
        while(cur->next!=NULL){
            cur = cur->next;
            count++;
        }
        ListNode* remove = head;
        int x = count - n;
        if(x==0)
        {
            return remove->next;
        }
        while(x>1){
            remove = remove->next;
            x--;
        }
        ListNode* temp = remove->next->next;
        remove->next = temp;

        return head;
    }
};