class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        map<int,int>Map;
        for (auto& meeting: meetings)
        {
            int a = meeting[0], b = meeting[1];
            Map[a]++;
            Map[b+1]--;
        }
        Map[days+1]+=1;
        
        int sum = 0;
        int cur = 1;
        int total = 0;
        for (auto [k,v]:Map)
        {
            if (sum==0 && sum+v>0)
            {
                total += k-cur;                
            }
            else if (sum>0 && sum+v==0)
            {
                cur = k;
            }
                        
            sum += v;
        }
        
        return total;
    }
};
