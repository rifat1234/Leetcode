class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int l,r;
        for(int i=0;i<(int)intervals.size();i++){
            int l1 = intervals[i][0];
            int r1 = intervals[i][1];

            if(!i)l=l1,r=r1;
            else {
                
                if(l1<=r)r=max(r,r1);
                else{
                    ans.push_back({l,r});
                    l = l1;
                    r = r1;
                }
            }
        }

        ans.push_back({l,r});
        return ans;
    }
};
