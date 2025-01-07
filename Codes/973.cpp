class Solution {
public:
    vector<pair<int,pair<int,int>>> f(vector<pair<int,pair<int,int>>> dist, int k){
        vector<pair<int,pair<int,int>>> left,right,mid;
        auto pivot = dist[(int)dist.size()/2].first;
        for(int i=0;i<(int)dist.size();i++){
            int val = dist[i].first;
            if(pivot == val)mid.push_back(dist[i]);
            else if(val > pivot)right.push_back(dist[i]);
            else left.push_back(dist[i]);
        }

        if(k<=(int)left.size())return f(left, k);
        else if (k<=(int)left.size()+(int)mid.size()){
            int diff = k - (int)left.size();
            for(int i=0;i<diff;i++)left.push_back(mid[i]);
            return left;
        } else {
            auto ret = f(right, k-(int)mid.size()-(int)left.size());
            for(auto val:left)ret.push_back(val);
            for(auto val:mid)ret.push_back(val);
            return ret;
        }

        return {};
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,pair<int,int>>> dist;
        for(auto point:points){
            int x = point[0], y = point[1];
            dist.push_back(make_pair(x*x+y*y,make_pair(x,y)));
        }

        auto nums = f(dist,k);
        vector<vector<int>> ans;
        for(auto num:nums){
            ans.push_back({num.second.first, num.second.second});
        }

        return ans;
    }
};
