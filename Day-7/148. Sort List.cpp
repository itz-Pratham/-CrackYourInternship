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
    ListNode* sortList(ListNode* head) {
        
        ListNode* current = head;
        ListNode* curent = head;
        vector<int> nums;
        while(current!=NULL){
            nums.push_back(current->val);
            current = current->next;
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            curent->val = nums[i];
            curent = curent->next;
        }

        return head;
    }
};