class Solution {
public:
//[1,12,-5,-6,50,3], k = 4
// sm = 2, ans = 12.75
    double findMaxAverage(vector<int>& nums, int k) {
        int sm = 0;
        for(int i=0;i<k;i++)sm+=nums[i];
        double ans = sm/(double)k;
        for(int i=1;i+k-1<nums.size();i++){
            sm-=nums[i-1];
            sm+=nums[i+k-1];
            ans = max(ans,sm/(double)k);
        }
        
        return ans;
    }
};
