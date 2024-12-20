class Solution{
    public:
    bool isPossible(int a[], int b[], int n, int k)
    {
        // Sort the array a[] in increasing order.
        sort(a, a + n);

        // Sort the array b[] in decreasing order.
        sort(b, b + n, greater<int>());

        // Checking condition on each index.
        for (int i = 0; i < n; i++)
            if (a[i] + b[i] < k)
                return false;

        return true;
    }
};