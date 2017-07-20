class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>results;
        vector<int>Qpos(n,-1);
        DFS(0,results,Qpos);
        return results;
    }
    
    void DFS(int row, vector<vector<string>>&results, vector<int>&Qpos)
    {
        int n = Qpos.size();
        
        if (row==n)
        {
            vector<string> board;
            for (int i=0; i<n; i++)
            {
                string temp;
                for (int j=0; j<n; j++)
                    temp+='.';
                temp[Qpos[i]]='Q';
                board.push_back(temp);
            }
            results.push_back(board);
        }
        else
        {
            for (int col=0; col<n; col++)
            {
                if (isValid(Qpos,row,col))
                {
                    Qpos[row]=col;
                    DFS(row+1,results,Qpos);
                    Qpos[row]=-1;
                }
            }
        }
    }
    
    bool isValid(vector<int>Qpos, int row, int col)
    {
        for (int i=0; i<row; i++)
        {
            if (Qpos[i]==col || abs(i-row)==abs(Qpos[i]-col))
                return false;
        }
        return true;
    }
};
