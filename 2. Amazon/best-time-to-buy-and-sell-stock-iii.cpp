class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_price1 = INT_MAX, profit1 = 0;
        int min_price2 = INT_MAX, profit2 = 0;
        
        int n = prices.size();
        for(int i=0; i<n; i++){
            min_price1 = min(min_price1, prices[i]);
            profit1 = max(profit1, prices[i]-min_price1);
            
            //Now 2nd Transcation 
            min_price2 = min(min_price2, prices[i]-profit1); //For 2nd Transaction efffective price is, current price - profit from 1st transcation
            profit2 = max(profit2, prices[i]-min_price2);
        }
        
        return profit2;
        
    }
};
