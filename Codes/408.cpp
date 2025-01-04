class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int idx = 0,num=0;
        for(int i=0;i<(int)abbr.size();i++){
            if(isdigit(abbr[i])){
                int digit = abbr[i]-'0';
                if(!digit && !num)return false;
                num = num*10+digit;
            } else {
                if(num){
                    idx+=num;
                    num=0;
                }

                if(idx>=(int)word.size())return false;
                if(word[idx++]!=abbr[i])return false;

            }
        }

        idx+=num; 
        if(idx!=word.size()){
            return false;
        }

        return true;
    }
};
