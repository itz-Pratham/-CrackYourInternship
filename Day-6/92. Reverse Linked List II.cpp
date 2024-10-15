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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* prev = NULL;
	ListNode* cur = head;
    int i=1;                            // pointer for marking in between ...
    for(i=1;i<left;i++){
        prev = cur;
        cur = cur->next;
    }
    ListNode* right_tail = cur;
    ListNode* right_head = NULL;

	while(i<=right){
        ListNode* temp = cur->next;
        cur->next = right_head;
        right_head = cur;
        cur = temp;
        i++;
    }

    if(prev!=NULL){
        prev->next = right_head;
    }
    else{
        head = right_head;
    }

	right_tail->next = cur;

    return head;
    }
};