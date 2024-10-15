class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        Node *cur1 = first;
        Node *cur2 = second;
        long long num1 = 0,num2 = 0;
        long long MOD = 1e9 + 7;
        
        while(cur1){
            num1 = (num1*10 + cur1->data) % MOD;
            cur1 = cur1->next;
        }
        while(cur2){
            num2 = (num2*10 + cur2->data) % MOD;
            cur2 = cur2->next;
        }
        long long prod = (num1*num2) % MOD;
        return prod;
    }
};