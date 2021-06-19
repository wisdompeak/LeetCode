typedef long long ll;
class Solution {
    int ret = 0;
public:
    int maxLength(vector<string>& arr) 
    {        
        vector<ll>codes;
        for (int i=0; i<arr.size(); i++)
        {
            ll code = 0;
            int flag = 1;
            for (auto ch: arr[i])
            {
                if ((code>>(ch-'a'))&1)
                {
                    flag = 0;
                    break;
                }
                code += (1<<(ch-'a'));
            }
            if (flag)
                codes.push_back(code);
        }

        ll bits = 0;
        for (int i=0; i<codes.size(); i++)
            dfs(codes, i, codes[i]);
        return ret;
    }

    void dfs(vector<ll>codes, int i, ll bits)
    {
        ret = max(ret, __builtin_popcount(bits));
        for (int j=i+1; j<codes.size(); j++)
        {
            if ((bits & codes[j])==0)
            {
                dfs(codes, j, bits + codes[j]);
            }            
        }
    }
};
