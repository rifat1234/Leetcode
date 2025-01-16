class Solution {
private:
    vector<int> ww;
public:
    Solution(vector<int>& w) {
        for(int i=1;i<(int)w.size();i++){
            w[i]+=w[i-1];
        }
        ww = w;
    }
    
    int pickIndex() {
        float randNum = (float) rand() / RAND_MAX;
        float val = randNum * ww.back();
        for(int i=0;i<(int)ww.size();i++){
            if(val<=ww[i])return i;
        }
        
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
