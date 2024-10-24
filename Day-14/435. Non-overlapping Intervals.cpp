class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), comp);
        int count_correct = 1;
        int prevEnd = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(prevEnd <= intervals[i][0]){
                count_correct++;
                prevEnd = intervals[i][1];
            }
        }
        return intervals.size()-count_correct;
    }
};