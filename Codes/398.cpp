class Solution {
private:
    unordered_map<int,vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int sz = mp[target].size();
        int r = rand()%sz;
        return mp[target][r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
