class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = (int)nums.size();
        int l =0,r=sz-1;
        
        while(l<r){
            int md = l + (r-l)/2;
            if(md+1<sz && nums[md+1]>nums[md])l=md+1;
            else r = md;
        }

        return l;
    }
};
