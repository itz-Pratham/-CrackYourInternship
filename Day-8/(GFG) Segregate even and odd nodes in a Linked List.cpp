class Solution{
    public:
    Node* segregateEvenOdd(Node* head) {
    
        Node* resStart = nullptr;
        Node* resEnd = nullptr;

        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
        
            if (curr->data % 2 == 0) {

                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {

                    head = curr->next; 
                }

                if (resStart == nullptr) {
                    resStart = curr;
                    resEnd = resStart;
                } else {
                    resEnd->next = curr;
                    resEnd = resEnd->next;
                }

                curr = curr->next;
            } 

            else {            
                prev = curr;
                curr = curr->next;
            }
        }

        if (resStart == nullptr)
            return head;

        resEnd->next = head;

        return resStart;
    }
};