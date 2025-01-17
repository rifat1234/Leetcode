//"11" "123"
//idx1 = -1, idx2 = 0
//ans = ['4','3','1']

class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size();
        int sz2 = num2.size();
        int idx1 = sz1-1;
        int idx2 = sz2-1;
        
        vector<char> ans;
        int e = 0;
        
        while(idx1!=-1 || idx2!=-1){
            int d1 = 0;
            int d2 = 0;
            
            
            if(idx1>=0){
                d1 = num1[idx1--]-'0';
            } 
            
            if(idx2>=0){
                d2 = num2[idx2--]-'0';
            }
            
            int sm = d1+d2+e;
            e = sm/10;
            ans.push_back( (sm%10)+'0' );
        }
        
        if(e)ans.push_back(e+'0');
        
        string ret = "";
        for(int i=ans.size()-1;i>=0;i--)ret+=ans[i];
        
        return ret;
    }
};
