class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        if(!num)return num;
        while(num){
            digits.push_back(num%10);
            num/=10;
        }
        
        reverse(digits.begin(), digits.end());
        
        int l=digits.size()-1, r= digits.size()-1;
        int idx_mx = digits.size()-1;
        for(int i=digits.size()-2;i>=0;i--){
            if(digits[i]<digits[idx_mx]){
                l = i;
                r = idx_mx;
            }
            if(digits[i]>digits[idx_mx]){
                idx_mx = i;
            }
        }
        
        swap(digits[l],digits[r]);
        int ans = 0;
        for(int i=0;i<digits.size();i++){
            ans*=10;
            ans+=digits[i];
        }
        
        return ans;
    }
};
