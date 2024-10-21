class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int totalKamai = 0;
        int totalKharch = 0;
        
        for(int i=0;i<n;i++){
            totalKamai += p[i].petrol;
            totalKharch += p[i].distance;
        }

        if(totalKamai < totalKharch)
            return -1;

        int res_idx = 0;
        int total = 0;

        for(int i=0;i<n;i++){
            total += p[i].petrol - p[i].distance;

            if(total < 0){
                res_idx = i+1;
                total = 0;
            }
        }
            
        return res_idx;
    }
};