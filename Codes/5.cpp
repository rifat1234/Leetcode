class Solution {
// /s = "babad"
private:
    pair<int,int> getPalin(int l, int r,string &s){
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--,r++;
        }
        
        return make_pair(l+1, r-1 );
    }
    
    pair<int,int> getBest(pair<int,int> a, pair<int,int> b){
        auto a1 = a.second - a.first;
        auto b1 = b.second - b.first;
        return a1>b1?a:b;
    }
public:
    string longestPalindrome(string s) {
        if(s.empty())return s;
        auto range = make_pair(0,0);
        for(int i=0;i<s.size();i++){
            auto a = getPalin(i,i,s);
            auto b = getPalin(i,i+1,s);
            range = getBest(range,getBest(a,b));
        }
        
        string ans = "";
        for(int i=range.first;i<=range.second;i++)ans+=s[i];
        return ans;
    }
};
