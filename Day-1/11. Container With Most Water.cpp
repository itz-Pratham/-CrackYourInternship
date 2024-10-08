class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = h.size();
        int i = 0;
        int j = n-1;

        int maxArea = 0; // or INT_MIN

        while(i < j) {

            // compute the area of the container which uses the ith and jth line

            int a_ij = (j-i)*min(h[i], h[j]);
            maxArea = max(maxArea, a_ij);

            if(h[i] < h[j]) {
                i++;
            } else {
                j--;
            }


        }

        return maxArea;
    }
};