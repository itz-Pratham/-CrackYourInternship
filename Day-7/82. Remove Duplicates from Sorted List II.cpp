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
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* prev = head;
        // ListNode* current = head;

        // while(current!=NULL && current->next!=NULL)
        // {
        //     if(current->val==current->next->val){
        //         int n= current->val;
        //         while(current->val==n)
        //         {
        //             current=current->next;
        //         }
        //         // current=current->next;
        //         prev->next=current;
        //     }

        //     else
        //     {
        //         prev=current;
        //         current=current->next;
        //     }
        // }
        // return prev;

        ListNode *dummy = new ListNode(0,head);
        ListNode *prev=dummy;
        
        while(head!=NULL){
        
            if(head->next!=NULL && head->val==head->next->val){
                    
                while(head->next!=NULL && head->val==head->next->val) head=head->next;

                prev->next=head->next;
            }
                    
            else prev=prev->next;
                    
            head=head->next;

        }
            
        return dummy->next;
                
    }
};