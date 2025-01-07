class Solution {
public:
    string simplifyPath(string path) {
        stack <string> stk;
        path+="/";
        string filename ="";

        for(int i=0;i<(int)path.size();i++){
            if(path[i]=='/'){
                if(filename.size()){
                    if(filename == ".."){
                        if(!stk.empty())stk.pop();
                    } else if(filename != "."){
                        stk.push(filename);
                    }
                }
                filename = "";
                continue;
            } 

            filename += path[i];
        }

        if(filename.size())stk.push(filename);

        string ans = "";
        while(!stk.empty()){
            ans = ("/"+stk.top()) + ans;
            stk.pop();
        }

        return ans.size() ? ans: "/";
    }
};
