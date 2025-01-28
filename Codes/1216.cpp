class Solution {
private:
    vector<vector<int>> mem;
public:
    int minRemove(int l, int r, string &s){
        if(l>=r)return 0;
        if(mem[l][r]!=-1)return mem[l][r];
        if(s[l]==s[r])return mem[l][r] = minRemove(l+1,r-1,s);
        else{
            return mem[l][r] = min(minRemove(l+1,r,s),minRemove(l,r-1,s))+1;
        }
    }
    bool isValidPalindrome(string s, int k) {
        mem.resize(s.size(), vector<int>(s.size(),-1));
        return minRemove(0,s.size()-1,s) <= k;
    }
};
