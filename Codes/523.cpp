class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sm(1,0);
        unordered_map<int,int> mp;
        int s = 0;
        for(auto n:nums){
            s+=n;
            sm.push_back(s);
        }
        
        for(int i=0;i<sm.size();i++){
            sm[i] = sm[i]%k;
            mp[sm[i]] = i;
        }
        
        for(int i=0;i<sm.size();i++){
            int idx = mp[sm[i]];
            int diff = idx - i;
            if(diff >= 2)return true;
        }
        
        return false;
        
    }
};
