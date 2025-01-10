//s = baac, o = ab
// cnt = [0,0,0]
// ans = "aabc", 
class Solution {
public:
    string customSortString(string order, string s) {
        vector <int> cnt(26,0);
        for(int i=0;i<s.size();i++)cnt[s[i]-'a']++;
        string ans = "";
        for(int i=0;i<order.size();i++)
            while(cnt[order[i]-'a']){
                ans+=order[i];
                cnt[order[i]-'a']--;
            }
            
        for(int i=0;i<cnt.size();i++){
            while(cnt[i]){
                ans+=(i+'a');
                cnt[i]--;
            }
        }
        
        return ans;
    }
};
