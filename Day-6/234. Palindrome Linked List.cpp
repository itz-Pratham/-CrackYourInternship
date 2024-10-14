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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        ListNode* end = head;
        int count = 0;

        if(cur->next == NULL)
            return true;

        while(end != NULL){
            end = end->next;
            count++;
        }

        stack<int> s;

        int n;

        if(count%2==0)  
            n = count/2 - 1;

        if(count%2!=0)
            n = count/2;

        for(int i=0;i<=n;i++){
            s.push(cur->val);
            cur = cur->next;
        }

        if(count%2 != 0)
            s.pop();

        while(!s.empty() and cur != NULL){
            if(s.top() == cur->val){
                s.pop();
                cur = cur->next;
            }
            else
                return false;
        }


        if(s.empty())
            return true;
        
        return false;


    }
};