class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int a=0; a<prices.size()-1; a++){
            if(prices[a] < prices[a+1]){
                ans += prices[a+1] - prices[a];
            }
        }
        return ans;
    }
};
