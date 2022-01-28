class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0, n = prices.size();
        
        for(int i=1; i<n; i++){
            if(prices[i]-prices[i-1]>0){
                max_profit += prices[i]-prices[i-1];
            }
        }
        
        return max_profit;
        
    }
};
