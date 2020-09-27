class Solution {
    vector<int>net;
public:
    bool check(int s, int n, vector<vector<int>>& requests, int& count)
    {
        int m = requests.size();     
        std::fill(net.begin(), net.end(), 0);

        for (int i=0; i<m; i++)
        {
            if (((s>>i)&1)==1)
            {
                net[requests[i][0]]++;
                net[requests[i][1]]--;
                count++;
            }
        }

        int flag = 1;
        for (int i=0; i<n; i++)
        {
            if (net[i]!=0)
            {
                flag= 0;
                break;
            }
        }

        return flag;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        int m = requests.size();        
        int ret = 0;
        net.resize(n);
        
        for (int state = 0; state < (1<<m); state++)
        {                      
            int count = 0;  
            if (check(state, n, requests, count))
                ret = max(ret, count);
        }
        return ret;        
    }
};
