class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 0;
        
        for(int i=0; i<intervals.size();i++){
            while(!q.empty() && q.top() <= intervals[i][0]){
                q.pop();
            }
            q.push(intervals[i][1]);
            ans = max((int)q.size(),ans);
        }
        
        return ans;
    }
};
