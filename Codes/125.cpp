class Solution {
public:
    bool isPalindrome(string s) {
        string ss="";
        for(int i=0;i<(int)s.size();i++){
            if(isalnum(s[i]))ss+=tolower(s[i]);
        }

        int l=0,r=(int)ss.size()-1;
        while(l<r){
            if(ss[l++]!=ss[r--])return false;
        }

        return true;
    }
};
