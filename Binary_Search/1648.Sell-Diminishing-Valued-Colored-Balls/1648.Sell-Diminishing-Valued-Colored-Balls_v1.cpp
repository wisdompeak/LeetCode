class Solution {
public:
    long long M = 1e9+7;
    int maxProfit(vector<int>& inventory, int orders) 
    {
        sort(inventory.begin(), inventory.end());
        reverse(inventory.begin(), inventory.end());
        int left = 1, right = inventory[0];
        while (left <right)
        {
            int mid = left+(right-left)/2;
            if (count(inventory, mid) <= orders)
                right = mid;
            else
                left = mid+1;
        }
        long long x = left;
        long long ret = 0;
        for (int i=0; i<inventory.size(); i++)
        {            
            if (inventory[i]<x) break;
            ret += (inventory[i]+x)*(inventory[i]-x+1)/2%M;
            ret %= M;
        }
        ret += (x-1)*(orders-count(inventory,x)) % M;
        ret %= M;

        return ret;
    }

    long long count(vector<int>&inventory, int k)
    {
        long long total = 0;
        for (int i=0; i<inventory.size(); i++)
        {
            if (inventory[i]<k) break;
            total += inventory[i]-k+1;
        }
        return total;
    }
};
