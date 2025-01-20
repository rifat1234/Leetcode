class Solution {
private:
    int countPalin(int l, int r, string &s){
        int cnt = 0;
        while(l>=0 && r<s.size()){
            if(s[l]!=s[r])break;
            cnt++;
            l--;
            r++;
        }
        
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            ans+=countPalin(i,i,s);
            ans+=countPalin(i,i+1,s);
        }
        
        return ans;
    }
};
