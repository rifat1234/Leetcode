class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int sz1 = firstList.size();
        int sz2 = secondList.size();
        int id1=0,id2=0;
        vector<vector<int>>ans;
        while(id1<sz1 && id2<sz2){
            int l = max(firstList[id1][0],secondList[id2][0]);
            int r = min(firstList[id1][1],secondList[id2][1]);
            if(l<=r){
              ans.push_back({l,r});  
            } 
            
            if(firstList[id1][1]<secondList[id2][1])id1++;
            else id2++;
        }
        
        return ans;
    }
};
