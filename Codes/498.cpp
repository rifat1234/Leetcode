class Solution {
public:
/*
Input: mat =[[1,2,3],
             [4,5,6],
             [7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
*/
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> ans;
        bool isRev = true;
        for(int i=0;i<c;i++){
            int x = 0, y = i;
            vector<int> values;
            while(x<r && y>=0){
                values.push_back(mat[x][y]);
                x++,y--;
            }
            
            if(isRev)reverse(values.begin(),values.end());
            isRev = !isRev;
            ans.insert(ans.end(),values.begin(),values.end());
        }
        
        for(int i=1;i<r;i++){
            int x = i, y = c-1;
            vector<int> values;
            while(x<r && y>=0){
                values.push_back(mat[x++][y--]);
            }
            
            if(isRev)reverse(values.begin(),values.end());
            isRev = !isRev;
            ans.insert(ans.end(),values.begin(),values.end());
        }
        
        return ans;
    }
};
