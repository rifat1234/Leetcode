class Solution {
private:
    string conv(string s){
        if(s.empty())return s;
        int diff = s[0]-'a';
        string ret = "";
        for(auto ch:s){
            int d = (ch-'a')-diff;
            if(d<0)d+=26;
            ret+=('a'+d);
        }
        
        return ret;
    }
    
    unordered_map<string,vector<string>> mp;
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        for(auto s:strings)mp[conv(s)].push_back(s);
        vector<vector<string>>ans;
        for(auto it:mp)ans.push_back(it.second);
        return ans;
    }
};
