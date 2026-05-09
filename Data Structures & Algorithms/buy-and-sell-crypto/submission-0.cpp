class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // 1. Allocate
        int min_price;
        int max_profit;
        int price_now;
        int profit_now;

        // 2. Init
        min_price = prices[0];
        max_profit = 0;

        // 3. Loop
        int pointer = 1;
        while (pointer < prices.size()){

            price_now = prices[pointer];

            if (price_now < min_price){
                min_price = price_now;
                continue;
            }
            else{
                profit_now = price_now - min_price;
                if (profit_now > max_profit)
                    max_profit = profit_now;
            }

            pointer++;
        }

        return max_profit;
    }
};
