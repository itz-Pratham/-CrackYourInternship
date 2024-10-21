class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalKamai = accumulate(begin(gas),end(gas),0);
        int totalKharch = accumulate(begin(cost),end(cost),0);

        if(totalKamai < totalKharch)
            return -1;

            int res_idx = 0;
            int total = 0;

            for(int i=0;i<n;i++){
                total += gas[i] - cost[i];

                if(total < 0){
                    res_idx = i+1;
                    total = 0;
                }
            }
            return res_idx;

    }
};