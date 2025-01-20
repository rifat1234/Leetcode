

class Solution {
private:
    vector<int> splitLog(string log){
        vector<int> ret;
        stringstream ss(log);
        string token;
        while(getline(ss,token, ':')){
            if(ret.size()==1){
                if(token == "start")ret.push_back(0);
                else ret.push_back(1);
            } else {
                ret.push_back(stoi(token));
            }
        }
        
        return ret;
    }
public:
//["0:start:0","1:start:2","1:end:5","0:end:6"]
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<vector<int>> stk;
        int lastTime = 0;
        
        for(auto log: logs){
            auto val = splitLog(log);
            if(val[1]){ // end
                auto tp = stk.top();
                int unit = val[2] - lastTime;
                ans[tp[0]]+=unit;
                stk.pop();
                lastTime = val[2];
            } else{ // start
                if(!stk.empty()){
                    auto tp = stk.top();
                    int unit = val[2] - lastTime-1;
                    ans[tp[0]]+=unit;
                }
                stk.push(val);
                lastTime = val[2]-1;
            }
        }
        
        return ans;
    }
};
