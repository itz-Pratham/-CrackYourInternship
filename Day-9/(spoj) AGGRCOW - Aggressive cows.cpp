#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

bool canPlaceCows(int c,int n,int*pos,int m)
{
    int numOfCowPlaced =1;
    int prevCowPos =0;

    for(int i=1;i<n;i++)
    {
        if(pos[i]-prevCowPos >=m)
        {
            numOfCowPlaced++;
            prevCowPos = pos[i];

            if (numOfCowPlaced == c) {
				return true;
			}

		}

	}

	return false;

}       


int largestMinDist(int n, int c, int* pos) {

	int s = INT_MAX; // for the tightest lower-bound, place the two cows in stalls closest to each other
	int e = pos[n - 1] - pos[0]; // for the tightest upper-bound, place the two cows at the extreme positions
	for (int i = 1; i < n; i++) {
		if (pos[i] - pos[i - 1] < s) {
			s = pos[i] - pos[i - 1];
		}
	}

	int ans;

	while (s <= e) {
		int m = s + (e - s) / 2;

		// can you place 'c' cows in 'n' stalls such that
		// the minimum distance b/w them is at-least 'm'?

		if (canPlaceCows(c, n, pos, m)) {
			// you can place 'c' cows in 'n' stalls
			ans = m;
			// since we want to find the largest minimum distance b/w
			// the cows, continue your search towards the right of 'm'
			// i.e. search space reduces from [s, e] to [m+1, e].
			s = m + 1;
		} else {
			// you cannot place 'c' cows in 'n' stalls at a minimum distance
			// of 'm' therefore continue your search towards the left of 'm'
			// i.e. search space reduces from [s, e] to [s, m-1].
			e = m - 1;
		}

	}

	return ans;

}

int main() {

	int t;
	cin >> t;

	int n, c;
	int* pos = new int[n];

	while (t--) {
		cin >> n >> c;
		for (int i = 0; i < n; i++) {
			cin >> pos[i];
		}
		sort(pos, pos + n);
		cout << largestMinDist(n, c, pos) << endl;
	}

	return 0;
}