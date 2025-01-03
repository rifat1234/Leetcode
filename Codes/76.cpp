

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_c;
        for(int i=0;i<t.size();i++){
            t_c[t[i]]++;
        }

        unordered_map<char,int> cur;
        int r = 0, mx=12345446,idx=-1;


        for(int i=0;i<s.size();i++){
            if (isValid(cur,t_c)){
                int new_mx = r-i;
                if(new_mx<mx){
                    mx = new_mx;
                    idx = i;
                }

            } else {
                while(r<s.size()){
                    cur[s[r++]]++;
                    
                    if(isValid(cur,t_c)){
                        int new_mx = r-i;
                        if(new_mx<mx){
                            mx = new_mx;
                            idx = i;
                        }
                        break;
                    }
                }
            }

            cur[s[i]]--;
        }

        string ans = "";
        if(idx!=-1)
            for(int i=idx;i<idx+mx;i++)ans+=s[i];
        return ans;
    }

    bool isValid(unordered_map<char,int> &s, unordered_map<char,int> &t){
        for(auto it = t.begin();it!=t.end();it++){
            auto key = it->first;
            auto value = it->second;
            if(value > s[key])return false;
        }

        return true;
    }
};
