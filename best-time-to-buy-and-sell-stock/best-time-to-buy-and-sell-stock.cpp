class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        int mine = INT_MAX;
        
        for(int i=0; i<prices.size(); i++){
            int max = prices[i];
            mine = min(mine,prices[i]);
            if(max-mine>profit){
                profit = max-mine;
            }
        }
        return profit;
        
    }
};