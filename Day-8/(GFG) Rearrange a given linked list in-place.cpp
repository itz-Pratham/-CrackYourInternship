// [Efficient Approach] By Reversing Second Half – O(n) Time and O(1) Space
// Find the middle of the linked list using the fast and slow pointer method. This involves moving one pointer twice as fast as the other so that when the faster pointer reaches the end, the slower pointer will be at the middle. 
// Reverse the second half of the list starting just after the middle node and split them in two parts.
// Merge the two halves together by alternating nodes from the first half with nodes from the reversed second half.

class Solution{
    public:
    Node *reverselist(Node *head) {
        Node *prev = nullptr, *curr = head, *next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    
    Node *rearrange(Node *head) {
  
        Node *slow = head, *fast = slow->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *head1 = head;
        Node *head2 = slow->next;
        slow->next = NULL;
        
        head2 = reverselist(head2);
        
        head = new Node(0); 
        Node *curr = head;
        while (head1 || head2) {
        
            if (head1) {
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }
        

            if (head2) {
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }
    

        return head->next;
    }
};
