using LL = long long;
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) 
    {
        int ret = 0;
        for (auto& comp : composition)
        {
            int left = 0, right = INT_MAX/2;
            while (left < right)
            {
                int mid = right-(right-left)/2;
                if (isOK(mid, n, budget, comp, stock, cost))
                    left = mid;
                else
                    right = mid-1;
            }
            ret = max(ret, left);
        }
        
        return ret;
    }
    
    bool isOK(int t, int n, int budget, vector<int>&comp, vector<int>& stock, vector<int>& cost)
    {
        LL total = 0;
        for (int i=0; i<n; i++)
        {
            total += (max(0LL, ((LL)t * comp[i] - stock[i]))) * cost[i];
            if (total > budget)
                return false;
        }
        return true;
    }
};
