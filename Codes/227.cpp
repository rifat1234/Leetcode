class Solution {
public:
    void doOp(stack<int> &stk, int sign, int num){
        if(sign){
            if(sign == 1){
                stk.push(num);
            } else if(sign==2){
                stk.push(-1*num);
            } else if(sign==3){
                int tp = stk.top();
                stk.pop();
                stk.push(tp*num);
            } else if(sign==4){
                int tp = stk.top();
                stk.pop();
                stk.push(tp/num);
            }
        } else{
            stk.push(num);
        }
    }

    int calculate(string s) {
        stack<int> stk;
        int num = 0, sign = 0;

        for(int i=0;i<(int)s.size();i++){
            if(s[i]==' ')continue;
            if(isdigit(s[i])){
                int digit = s[i]-'0';
                num = num*10+digit;
            } else {
                doOp(stk,sign,num);
                num = 0;
                sign = s[i]=='+'?1:s[i]=='-'?2:s[i]=='*'?3:4;
            }
        }

        doOp(stk,sign,num);
        
        int ans=0;
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }

        return ans;
    }
};
