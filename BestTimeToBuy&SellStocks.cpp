class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size()<=1){
        return 0;
    }
   vector<vector<int>>dp(prices.size(),vector<int>(2,0));
    
    if(prices.size()==2 && prices[0]>prices[1]){
        return 0;
    }
    if(prices.size()==2 && prices[0]<=prices[1]){
        return prices[1]-prices[0];
    }
    
    // main 
    dp[0][0]= -1*prices[0]; // buy
    dp[0][1]=  0; //sell
        
    dp[1][0]=  -1* min(prices[1],prices[0]);
    dp[1][1]=    max(0,prices[1]-prices[0]);
    
    for(int i=2;i<prices.size();i++){
        dp[i][0] = max(dp[i-1][0] , dp[i-2][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1] , dp[i-1][0]+prices[i]);
    }
    
    return dp[prices.size()-1][1];
    }
};
