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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {

        ListNode* head = NULL;
        int carry = 0;

        while (head1 != NULL || head2 != NULL || carry == 1) {

            int d1 = head1 != NULL ? head1->val : 0;
            int d2 = head2 != NULL ? head2->val : 0;

            int sum = d1 + d2 + carry;

            ListNode* n = new ListNode(sum % 10);

            n->next = head;
            head = n;

            carry = sum / 10;

            head1 = head1 != NULL ? head1->next : head1;
            head2 = head2 != NULL ? head2->next : head2;

        }

    ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur != NULL) {

		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;

	}

	return prev;

    }
};