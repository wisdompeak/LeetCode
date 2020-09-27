class Solution {
    vector<int>net;
public:
    bool check(int s, int n, vector<vector<int>>& requests)
    {
        int m = requests.size();     
        std::fill(net.begin(), net.end(), 0);

        for (int i=0; i<m; i++)
        {
            if (((s>>i)&1)==1)
            {
                net[requests[i][0]]++;
                net[requests[i][1]]--;
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
        
        for (int r = m; r>=1; r--)
        {
            vector<int>arr(m);
            for (int i=m-r; i<m; i++)
                arr[i] = 1;
            
            while (1)
            {
                int state = 0;
                for (int i=0; i<m; i++)
                    if (arr[i]==1)
                        state+=(1<<i);

                if (check(state, n, requests))
                    return r;

                if (next_permutation(arr.begin(), arr.end())==false)
                    break;
            }
        }
        return 0;
    }
};
