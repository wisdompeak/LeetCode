class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) 
    {
        sort(inventory.begin(), inventory.end());
        reverse(inventory.begin(), inventory.end());
        int n = inventory.size();
        inventory.push_back(0);
        long long M = 1e9+7;
        
        long long ret = 0;
        for (int i=0; i<n; i++)
        {
            long long a = inventory[i];
            long long b = inventory[i+1];
            long long total = (a-b)*(i+1);
            
            if (total <= (long long)orders)
            {
                ret += (a+b+1)*(a-b)/2*(i+1);
                orders -= total;
                ret %= M;
            }
            else
            {                
                long long k = orders/(i+1);
                ret += (a+a-k+1)*k/2*(i+1);
                ret %= M;
                                
                long long m = orders%(i+1);
                ret += (a-k)*m;
                ret %= M;
                break;
            }                                   
            if (orders<=0) break;
        }
        return ret;
        
    }
};
