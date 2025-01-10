class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0,mx=0;
        for(int i=(int)prices.size()-1;i>=0;i--){
            ans = max(mx-prices[i],ans);
            mx = max(prices[i],mx);
        }
        return ans;
    }
};
