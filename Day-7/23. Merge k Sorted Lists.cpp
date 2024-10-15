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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<int> values;

        for(int i=0;i<k;i++){               // collect all elements individually in an array
            ListNode* temp = lists[i];
            while(temp!=NULL){
                values.push_back(temp->val);
                temp=temp->next;
            }
        }

        sort(values.begin(),values.end(),greater<int>());  // sort all those elements for greatest to lowest

        ListNode* head = NULL;              // make a head pointer for resulting list

        for(auto it : values){                      // input all values of the array by connecting it to a new node
            ListNode* node = new ListNode(it);      // we make a new node here everytime we encounter a new element
            node->next = head;                      // we connect the new node to the previous head i.e. its next node
            head = node;                            // we change head position to the start of the list
        }

        return head;
    }
};