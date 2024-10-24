#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        m--;
        n--;
        int x[n];
        int y[n];
        for(int i=0;i<m;i++) cin>>x[i];
        for(int j=0;j<n;j++) cin>>y[j];
        sort(x,x+m,greater<int>());
        sort(y,y+n,greater<int>());

        int horizontal_count = 1;
        int vertical_count = 1;

        int ans = 0;
        int i = 0;
        int j = 0;
        while(i<m && j<n){
            if(x[i]>y[j]){
                ans += x[i]*vertical_count;
                horizontal_count++;
                i++;
            }
            else{
                ans += y[j]*horizontal_count;
                vertical_count++;
                j++;
            }
        } 
        while(i<m){
            ans += x[i]*vertical_count;
            i++;
        }
        while(j<n){
            ans += y[j]*vertical_count;
            j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}