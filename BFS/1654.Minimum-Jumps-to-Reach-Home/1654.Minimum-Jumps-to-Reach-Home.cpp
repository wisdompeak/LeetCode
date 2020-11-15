class Solution {
    int visited[8001][2];
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
    {
        if (x==0) return 0;
        int max_forbid = *max_element(forbidden.begin(), forbidden.end());
        int limit = max(x, max_forbid)+b;

        for (auto x:forbidden)
        {
            visited[x][0] = -1;
            visited[x][1] = -1;
        }
        visited[0][0] = 0;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        int step = 0;

        while (!q.empty())
        {
            int len = q.size();
            step++;
            while (len--)
            {
                int i = q.front().first;
                int k = q.front().second;
                q.pop();

                if (i <= limit && visited[i+a][0] == 0)
                {
                    visited[i+a][0] = 1;
                    q.push({i+a,0});
                    if (i+a==x) return step;
                }
                
                if (k==0)
                {
                    if (i-b>=0 && visited[i-b][1] == 0)
                    {
                        visited[i-b][1] = 1;
                        q.push({i-b,1});
                        if (i-b==x) return step;
                    }
                }
            }
        }
        return -1;
    }
};
