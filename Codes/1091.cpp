//[[0,1],[1,0]]
class Solution {
public:
    bool isValid(int x, int y, int r, int c){
        return (x>=0 && x<r) && (y>=0 && y<c);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> xx = {-1,-1,1,1,0,0,1,-1};
        vector<int> yy = {1,-1,1,-1,1,-1,0,0};
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<bool>> vis(r,vector<bool>(c,false));

        if(grid[0][0])return -1;        
        vis[0][0] = true;
        queue<pair<int,int>> q;
        queue <int> d;
        q.push(make_pair(0,0));
        d.push(1);

        while(!q.empty()){
            auto x = q.front().first;
            auto y = q.front().second;
            auto w = d.front();
            q.pop(),d.pop();

            if(x==r-1 && y==c-1)return w;

            for(int i=0;i<8;i++){
                int x1 = x+xx[i];
                int y1 = y+yy[i];
                if(isValid(x1,y1,r,c) && grid[x1][y1]==0 && !vis[x1][y1]){
                    vis[x1][y1] = true;
                    q.push(make_pair(x1,y1));
                    d.push(w+1);
                }
            }
        }

        return -1;
    }
};
