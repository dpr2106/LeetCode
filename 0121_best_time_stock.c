int maxProfit(int* prices, int pricesSize) {
    int cheapest_price = INT_MAX;
    int max_profit = 0;
    for (int i = 0 ; i < pricesSize ; i++){
        if (prices[i] < cheapest_price){
            cheapest_price = price[i];

        }
        else{
           int temp_current_profit = prices[i] - cheapest_price;
           if(temp_current_profit > max_profit){
            max_profit = temp_current_profit;
           }
        }
    }
    return max_profit;
}