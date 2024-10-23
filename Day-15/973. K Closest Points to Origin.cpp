class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(int i=0;i<points.size();i++){
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            if (pq.size() < k) {
                pq.push({dist, {points[i][0], points[i][1]}});
            } else if (pq.top().first > dist) {
                pq.pop();
                pq.push({dist, {points[i][0], points[i][1]}});
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            vector<int> temp = pq.top().second;
            res.push_back(temp);
            pq.pop();
        }

        return res;
    }
};