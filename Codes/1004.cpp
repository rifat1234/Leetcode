class Solution {
public:
//[1,1,1,0,0,0,1,1,1,1,0], k=2
    int longestOnes(vector<int>& nums, int k) {
        int sz = nums.size(), r = 0,cnt = 0,ans =0;
        for(int l=0;l<sz;l++){
            while(cnt<=k && r<sz){
                cnt += (1-nums[r]);;
                if(cnt<=k){
                    ans = max(ans,r-l+1);
                } 
                r++;
            }
            
            cnt -= (1-nums[l]);
        }
        
        return ans;
    }
};
