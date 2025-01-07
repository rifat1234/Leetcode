class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;
        for(auto num:nums)mp[num]++;
        for(int i=0;i<(int)nums.size();i++){
            mp[nums[i]]--;
            int diff = target-nums[i];
            if(mp[diff]){
                for(int j=i+1;j<(int)nums.size();j++)
                    if(nums[j]==diff)return vector<int>{i,j};
            }
        }

        return vector<int>();
        
    }
};
