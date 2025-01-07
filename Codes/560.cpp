//[1,1,1]
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> mp;
        for(int num:nums){
           sum+=num;
           mp[sum]++; 
        }

        sum = 0;
        int ans = 0;
        for(int i=0;i<(int)nums.size();i++){
            int val = k + sum;
            ans+=mp[val];
            sum+=nums[i];
            mp[sum]--;
        }

        return ans;
        
    }
};
