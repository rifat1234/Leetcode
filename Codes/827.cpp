class Solution {
    //grid = [[1,0],[0,1]]
private:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    bool isValid(int i, int j, int n){
        return (i>=0 && i<n && j>=0 && j<n);
    }
    
    int dfs(int i,int j, vector<vector<int>> &grid, int marker){
        if(!isValid(i,j,grid.size()) || grid[i][j]!=1)return 0;
        grid[i][j] = marker;
        int ret = 1;
        for(int k=0;k<4;k++){
            int x1 = i+x[k];
            int y1 = j+y[k];
            ret+=dfs(x1,y1,grid,marker);
        }
        
        return ret;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        unordered_map<int,int> mp;
        int marker = 2,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int sz = dfs(i,j,grid,marker);
                    mp[marker++] = sz;
                    ans = max(ans,sz);
                }
            }
        }
        
        
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int sm = 1;
                    set<int> seen;
                    for(int k=0;k<4;k++){
                        int x1 = i+x[k];
                        int y1 = j+y[k];
                        
                        if(isValid(x1,y1,n) && grid[x1][y1] && !seen.contains(grid[x1][y1])){
                            seen.insert(grid[x1][y1]);
                            sm+=mp[grid[x1][y1]];
                        }
                    }
                    
                    ans = max(ans,sm);
                }
            }
            
        return ans;
    }
};
