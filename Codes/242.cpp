class Solution {
public:
//s = "ana", t = "naa"
//tCount = {0:2, 13:1}
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> tCount(26,0), sCount(26,0);
        for(int i=0;i<s.size();i++){
            tCount[t[i]-'a']++;
            sCount[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)if(tCount[i]!=sCount[i])return false;
        
        return true;
    }
};
