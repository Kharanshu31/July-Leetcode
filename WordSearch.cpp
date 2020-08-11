class Solution {
public:
    
    bool dfs(vector<vector<char>> &board,string word,vector<vector<bool>>& visit,int i, int j, int index,int r,int c)
    {
        if(board[i][j]==word[index])
        {
            visit[i][j]=true;
            if(index==word.length()-1)
                return true;
            if(i>=1 && visit[i-1][j]==false)
            {
                if(dfs(board,word,visit,i-1,j,index+1,r,c))
                    return true;
            }
            if(i<r-1 && visit[i+1][j]==false)
            {
                if(dfs(board,word,visit,i+1,j,index+1,r,c))
                    return true;
            }
            if(j>=1 && visit[i][j-1]==false)
            {
                if(dfs(board,word,visit,i,j-1,index+1,r,c))
                    return true;
            }
            if(j<c-1 && visit[i][j+1]==false)
            {
                if(dfs(board,word,visit,i,j+1,index+1,r,c))
                    return true;
            }
            visit[i][j]=false;
            return false;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        // vector<vector<bool>>& visit(r,vector<bool>(c,false));
        vector<vector<bool>>visit(r,vector<bool>(c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(dfs(board,word,visit,i,j,0,r,c))
                    return true;
            }
        }
        
        return false;
    }
};
