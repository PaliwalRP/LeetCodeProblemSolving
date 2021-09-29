class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int stock = -prices[0];
        int money = 0;
        int prev_money = 0;
        for(int i = 1; i < n; ++i){
            // before:
            // stock = stock[i]
            // prev_money = money[i - 1]
            // after:
            // stock = stock[i + 1]
            stock = max(stock, prev_money - prices[i]);
            // money = money[i]
            prev_money = money;
            // before:
            // money = money[i]
            // stock = stock[i + 1]
            // if stock[i + 1] = stock[i]
            // <==> stock[i] > money[i - 1] - prices[i]
            // then it does the same as the previous solution
            // else stock[i] < money[i - 1] - prices[i]
            // ==> stock[i + 1] = money[i - 1] - prices[i]
            // ==> stock + prices[i] = stock[i + 1] + prices[i]
            // = money[i - 1] - prices[i] + prices[i + 1]
            // = money[i - 1] <= money = money[i]
            // thus money[i + 1] must be money[i]
            money = max(stock + prices[i], money);
        }
        return money;
    }
};