class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        auto st = vector<int> ();
        f(0,st,nums, ans);
        return ans;
    }
    
    void f(int idx, vector<int> &st, vector<int> &nums, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(st);
            return;
        }
        
        st.push_back(nums[idx]);
        f(idx+1,st, nums,ans);
        st.pop_back();
        f(idx+1,st, nums,ans);
    }
};
