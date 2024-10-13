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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (head1 != NULL and head2 != NULL) {

            if (head1->val < head2->val) {

                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;

            } else {

                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;

            }

        }

        while (head1 != NULL) {

            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;

        }

        while (head2 != NULL) {

            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;

        }

        return dummy->next;

    }
};