class Solution {
    vector<int>Father;
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
        if (x<y) Father[y] = x;
        else Father[x] = y;
    } 
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) 
    {
        Father.resize(n);
        for (int i=0; i<n; i++) Father[i] = i;

        vector<bool>rets;
        for (auto& req: requests)
        {
            int x = req[0], y = req[1];
            int f_x = FindFather(x), f_y = FindFather(y);
            if (f_x == f_y)
            {
                rets.push_back(true);
                continue;
            }
            int flag = 1;
            for (auto& res: restrictions)
            {
                int a = res[0], b = res[1];
                int f_a = FindFather(a), f_b = FindFather(b);
                if ((f_a==f_x && f_b==f_y) || (f_a==f_y && f_b==f_x))
                {
                    flag = 0;
                    break;
                }
            }
            rets.push_back(flag==1);
            if (flag==1) Union(x,y);
        }
        return rets;        
    }
};
