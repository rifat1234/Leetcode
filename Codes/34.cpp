// 1,2,2,3,4
// l1 = 5, r1=4, md = 4
// l2 = 1, r2 = 0, md = 0
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = (int)nums.size();
        int l1=0,r1=sz-1;
        while(l1<=r1){
            int md = l1 + (r1-l1)/2;
            if(target<nums[md])r1 = md-1;
            else l1 = md+1;
        }

        int l2=0,r2=sz-1;
        while(l2<=r2){
            int md = l2 + (r2-l2)/2;
            if(target<=nums[md])r2 = md-1;
            else l2 = md+1;
        }

        if(l2>r1)return {-1,-1};
        return {l2,r1};
    }
};
