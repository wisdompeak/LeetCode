class Solution {
public:
    string minInteger(string num, int k) 
    {
        int n = num.size();
        vector<int>next(10,-1);
        vector<int>offset(10,0);
        for (int i=0; i<n; i++)
        {
            if (next[num[i]-'0']==-1)
                next[num[i]-'0'] = i;
        }

        vector<int>used(n, 0);
        string ret;
        auto ans = num;

        for (int i=0; i<num.size(); i++)
        {
            int j;
            for (j=0; j<10; j++)
            {
                if (next[j]==-1) continue;
                int d = next[j] + offset[j] - i;
                if (d <= k)
                {
                    k-=d;
                    break;
                }
            }
            ans[i] = num[next[j]];
            used[next[j]] = true;

            for (int k=0; k<10; k++)
            {
                if (next[k] < next[j])
                    offset[k]++;
            }

            int start = next[j];
            next[j] = -1;
            for (int k=start+1; k<n; k++)
            {
                if (used[k]==true)
                    offset[j]--;
                else if (num[k]==(j+'0'))
                {
                    next[j] = k;
                    break;
                }
            }            
        }
        return ans;
    }
};
