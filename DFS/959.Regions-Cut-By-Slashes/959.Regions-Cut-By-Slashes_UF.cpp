class Solution {
    vector<int>Father;
public:
    int regionsBySlashes(vector<string>& grid) 
    {
        int N = grid.size();
        Father.resize((N+1)*(N+1));
        for (int i=0; i<=N; i++)
            for (int j=0; j<=N; j++)
            {
                int id = i*(N+1)+j;
                Father[id] = id;
                if (i==0 || i==N || j==0 || j==N)
                    Father[id] = 0;
            }

        int count = 1;
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                int a,b;
                if (grid[i][j]==' ')
                    continue;

                if (grid[i][j]=='/')
                {
                    a = i*(N+1)+j+1;
                    b = (i+1)*(N+1)+j;
                }
                else if (grid[i][j]=='\\')
                {
                    a = i*(N+1)+j;
                    b = (i+1)*(N+1)+j+1; 
                }

                if (FindFather(a)!=FindFather(b))
                    Union(a,b);
                else
                    count++;
            }
        return count;
    }

    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y)
            Father[y] = x;
        else
            Father[x] = y;
    }    
};
