class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for(char aq : tasks){
            count[aq - 'A']++;
        }
        sort(begin(count) , end(count));

        int chunk = count[25] - 1;
        int idel = chunk * n;

        for(int i=24; i>=0; i--){
            idel -= min(chunk,count[i]);
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};