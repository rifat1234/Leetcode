class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int r = (int)nums.size()-1;
        while(r){
            if(nums[r]>nums[r-1]){
                break;
            }
            
            r--;
        }
        
        if(!r)reverse(nums.begin(), nums.end());
        else {
            int idx = r, mn = nums[r], val = nums[r-1];
            for(int i=r+1;i<nums.size();i++){
                if(val<nums[i] && nums[i]<=mn){
                    mn = nums[i];
                    idx = i;
                }
            }
            
            swap(nums[idx], nums[r-1]);
            reverse(nums.begin()+r, nums.end());
        }
    }
};
