class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int m = box.size();
        int n = box[0].size();
        
        auto rets = vector<vector<char>>(n, vector<char>(m,'.'));
        
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                int count = 0;
                int k = j;
                while (k<n && box[i][k]!='*')
                {
                    if (box[i][k]=='#')
                        count++;
                    k++;
                }
                
                int col = m-1-i;
                if (k!=n)
                    rets[k][col] = '*';
                
                for (int s=0; s<count; s++)
                    rets[k-1-s][col] = '#';
                
                j = k;
            }
        }
        
        return rets;
    }
};
