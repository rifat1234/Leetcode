class Solution {
    //Input: nums = [0,0,1,3,50,75,99], lower = 0, upper = 99
    //nums = [-1,-1,-1], lower = -1, upper = -1
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0){
            return vector<vector<int>>{{lower,upper}};
        }

        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(!i && nums[i] - lower > 0){
                ans.push_back({lower, nums[i]-1});
            }
             
            if(i && nums[i]-nums[i-1] > 1){
                ans.push_back( {nums[i-1]+1,nums[i]-1});
            }

             if(i+1==nums.size() && upper - nums[i]>0){
                ans.push_back({nums[i]+1, upper});
            }
        }
        
        return ans;
    }
};
