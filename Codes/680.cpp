class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=(int)s.size()-1;
        bool isPalin = true, chance = true;
        while(l<r){
            if(s[l]!=s[r]){
                if(chance){
                    l++;
                    chance=false;
                    continue;
                }

                isPalin = false;
            }

            l++,r--;
        }

        if(isPalin)return true;


        l=0,r=(int)s.size()-1;
        isPalin = true, chance = true;
        while(l<r){
            if(s[l]!=s[r]){
                if(chance){
                    r--;
                    chance=false;
                    continue;
                }

                isPalin = false;
            }

            l++,r--;
        }

        return isPalin;
    }
};
