class Solution {
    int memo[1<<24];
    int N;    
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        N=price.size();
        vector<vector<int>>specials;
        for (int i=0; i<special.size(); i++)
        {
            int sum=0;
            for (int j=0; j<N; j++)
                sum+=special[i][j]*price[j];
            if (sum>special[i].back())
                specials.push_back(special[i]);
        }

        int state = 0;
        for (int i=0; i<N; i++)
            state += needs[i]<<(i*4);
                
        return dfs(state, price,specials);
    }
    
    int dfs(int state, vector<int>& price, vector<vector<int>>& specials)
    {        
        if (memo[state]!=0) return memo[state];

        int ret = 0;
        for (int i=0; i<N; i++)
            ret += (state>>(i*4))%16 * price[i];

        for (auto comb: specials)
        {
            int flag = 1;
            for (int i=0; i<N; i++)
            {
                if ((state>>(i*4))%16 < comb[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag==0) continue;

            int state2 = state;
            for (int i=0; i<N; i++)
                state2 -= comb[i]*(1<<(i*4));
            ret = min(ret, comb[N] + dfs(state2, price, specials));
        }

        memo[state] = ret;
        return ret;
    }    
};
