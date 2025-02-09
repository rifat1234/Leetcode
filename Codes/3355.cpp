class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> l(nums.size()+1,0);
        for(int i=0;i<queries.size();i++){
            l[queries[i][0]]--;
            l[queries[i][1]+1]++;
        }
        
        int adder = 0;
        for(int i=0;i<nums.size();i++){
            adder+=l[i];
            nums[i] = max(0,nums[i]+adder);
        }
        
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
    
        return (!mx && !mn);
    }
};
