class Solution {
public:
    bool Dfs(vector<vector<bool>>&visited,vector<vector<char>>& board,int i,int j,string word,int idx){
        
        if(idx == (int)word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (visited[i][j] || board[i][j] != word[idx]) return false;

        
        visited[i][j] = true;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        for(int k = 0;k<4;k++){
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (Dfs(visited,board, ni, nj, word, idx + 1)) {
                return true; 
            }
        }
       visited[i][j] = false;
       return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(Dfs(visited,board,i,j,word,0)) return true;
            }
        }
        return false;
    }
};