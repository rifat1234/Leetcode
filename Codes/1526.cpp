class Solution {
public:
    //[3,1,1,2]
    // ans = 4, cur = 2, i = 3
    int minNumberOperations(vector<int>& target) {
        int ans = 0, cur = 0;
        
        for(int i=0;i<target.size();i++){
            if(cur < target[i]) ans+=(target[i]-cur);
            cur = target[i];
        }
        
        return ans;
    }
};
