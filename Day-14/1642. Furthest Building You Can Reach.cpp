class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        int i=0;
        priority_queue<int> pq;
        for(i;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            int d = heights[i+1]-heights[i];
            if(b>=d){
                b-=d;
                pq.push(d);

            }
            else if(l>0){
                if(!pq.empty() && pq.top() > d){
                    b+=pq.top();
                    pq.pop();
                    pq.push(d);
                    b-=d;
                }
                l--;
            }
            else break;
        }
        return i;
    }
};