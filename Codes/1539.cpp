// 1,2,3,4 k = 2
// l = 4, r = 3, md = 3
// 1,3,5,6 k = 2
// l = 2, r = 1, md = 2

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int sz = (int)arr.size();
        int l = 0, r=(int)sz-1;
        while(l<=r){
            int md = l + (r-l)/2;
            int diff = arr[md] - (md+1);
            if(diff >= k) r = md-1;
            else l = md+1;
        }
        
        if(!l)return k;
        int diff = arr[l-1]-l;
        return arr[l-1] + (k-diff);
    }
};
