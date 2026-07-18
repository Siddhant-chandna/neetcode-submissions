class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,sell=INT_MIN;
        for(auto x:prices){
            buy=min(buy, x);
            sell=max(sell, x-buy);
        }
        return sell; 
    }
};
