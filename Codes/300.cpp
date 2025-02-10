class Solution {
private:
    vector<int> mem;
public:
    // nums = [1,0,2]
    int dp(int idx, vector<int> &nums){
        if(mem[idx])return mem[idx];
        
        int ret = 0;
        for(int i=idx+1;i<nums.size();i++){
            if(nums[idx]<nums[i]){
                ret = max(ret,dp(i,nums));
            }
        }
        
        return mem[idx] = ret+1;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        mem.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++)
            ans = max(ans,dp(i, nums));
        return ans;
    }
};
