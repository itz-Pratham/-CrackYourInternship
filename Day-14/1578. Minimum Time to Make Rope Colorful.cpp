class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans;
        int sum,maxVal;
        bool flag=false;
        sum=neededTime[0];
        maxVal=neededTime[0];
        for(int i=1;i<colors.size();i++){

            if(flag==true){
               // cout<<"Skipped iteration no. : "<<i<<endl;
                flag=false;
                continue;
            }

            if(colors[i]!=colors[i-1]){
                //cout<<"Entering the if loop"<<endl;
                
                sum-=maxVal;
                maxVal=0;

                //cout<<sum <<" and "<<maxVal<<endl;

                if(colors[i]==colors[i+1]){
                    sum+=neededTime[i];
                    maxVal=max(maxVal,neededTime[i]);
                }
                
                if(colors[i+1] && colors[i+2] && colors[i+1]==colors[i+2]){
                    
                    //cout<<"Entering the extra if loop"<<endl;

                    sum+=neededTime[i+1];
                    maxVal=max(maxVal,neededTime[i+1]);
                    flag=true;

                   // cout<<"Sum : "<<sum<<" and maxVal : "<<maxVal<<endl;

                    //cout<<"Exiting the extra if loop"<<endl;
                }
                //cout<<"Exiting the if loop"<<endl;
                continue;
            }

            sum+=neededTime[i];
            maxVal=max(maxVal,neededTime[i]);    

            //cout<<"Loop : "<<i<<" : "<<sum <<" and "<<maxVal<<" Flag = "<<flag<<endl;
        }
        if(maxVal!=0){
            sum-=maxVal;
        }
        return sum;
    }
};