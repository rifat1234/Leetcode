class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i && nums[i-1]==nums[i])continue;
            int l = i+1, r=nums.size()-1;
            while(l<r){
                int sm = nums[l]+nums[i]+nums[r];
                if(sm>0)r--;
                else if(sm<0)l++;
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;
                    while(l<r && nums[l-1]==nums[l]){
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};
