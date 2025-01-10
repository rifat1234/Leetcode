class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        queue<pair<int,int>> q;
        
        int xx[] = {1,-1,0,0};
        int yy[] = {0,0,-1,1};
        int ans = 0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        vis[x][y] = true;
                        
                        for(int k=0;k<4;k++){
                            int x1 = x + xx[k];
                            int y1 = y + yy[k];
                            
                            if(isValid(x1,y1,r,c) && grid[x1][y1]=='1' && vis[x1][y1] == false){
                                vis[x1][y1] = true;
                                q.push(make_pair(x1,y1));
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    bool isValid(int x, int y, int r, int c){
        return (x>=0 && x<r) && (y>=0 && y<c);
    }
};
