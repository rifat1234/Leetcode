class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto num:nums)mp[num]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(auto val:mp){
            q.push(make_pair(val.second,val.first));
            if(q.size() > k)q.pop();
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};
