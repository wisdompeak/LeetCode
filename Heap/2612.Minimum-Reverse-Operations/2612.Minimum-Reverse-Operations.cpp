class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) 
    {
        set<int>odd;
        set<int>even;
        set<int>banned_set(banned.begin(), banned.end());
        for (int i=0; i<n; i++)
        {
            if (banned_set.find(i)!=banned_set.end()) continue;
            if (i==p) continue;
            if (i%2==0) even.insert(i);
            else odd.insert(i);
        }

        queue<int>q;
        q.push(p);
        vector<int>rets(n, -1);
        rets[p] = 0;

        int step = 0;
        while (!q.empty())
        {
            step++;
            int len = q.size();
            while (len--)
            {
                int i = q.front();
                q.pop();
                int L0 = max(0, i-k+1);
                int j0 = (2*L0+k-1)-i;

                int L1 = min(n-k, i);                
                int j1 = (2*L1+k-1)-i;

                set<int>*s;
                if (j0%2==0) s = &even;
                else s = &odd;

                auto iter = s->lower_bound(j0);
                while (iter!=s->end() && *iter<=j1)
                {
                    rets[*iter] = step;
                    q.push(*iter);
                    s->erase(iter++);
                }
            }
        }

        return rets;
    }
};
