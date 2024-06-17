class Solution {
public:
    void spread(vector<vector<char>>& grid,vector<vector<bool>>& b,int i,int j){
        b[i][j]=1;
        if(i<grid.size()-1&&grid[i+1][j]=='1'&&!b[i+1][j]) spread(grid,b,i+1,j);
        if(i>0&&grid[i-1][j]=='1'&&!b[i-1][j]) spread(grid,b,i-1,j);
        if(j<grid[0].size()-1&&grid[i][j+1]=='1'&&!b[i][j+1]) spread(grid,b,i,j+1);
        if(j>0&&grid[i][j-1]=='1'&&!b[i][j-1]) spread(grid,b,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>b(n,vector<bool>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!b[i][j]){
                    spread(grid,b,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
