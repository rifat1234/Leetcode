//[1,0,1,0,1] k = 2
//mp = {0:0,1:2,2:4}
// ans = 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            cnt+=(!nums[i]?1:0);
            mp[cnt]=i;
        }
        
        int ans = 0, z = 0;
        for(int i=0;i<nums.size();i++){
            int mx = min(cnt, z+k);
            if (mp.count(mx)) ans = max(mp[mx]-i+1,ans);
            z+=(!nums[i]?1:0);
        }
        
        return ans;
    }
};
