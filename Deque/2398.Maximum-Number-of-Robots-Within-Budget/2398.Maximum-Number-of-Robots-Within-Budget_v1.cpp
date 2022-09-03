using LL = long long;
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) 
    {
        vector<pair<LL,LL>>robots;
        int n = chargeTimes.size();
        
        LL left = 0, right = n;
        while (left < right)
        {
            LL mid = right-(right-left)/2;            
            if (isOK(mid, chargeTimes, runningCosts, budget))
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
    
    bool isOK(LL k, vector<int>& chargeTimes, vector<int>& runningCosts, long long budget)
    {
        LL n = chargeTimes.size();
        LL sum = 0;              
        multiset<LL>Set;            
        
        for (int i=0; i<n; i++)
        {            
            sum += runningCosts[i];
            Set.insert(chargeTimes[i]);
            
            if (i>=k-1)
            {   
                LL ret = *(Set.rbegin()) + (LL)k * sum;
                if (ret <= budget) return true;
                sum -= runningCosts[i-k+1];
                Set.erase(Set.find(chargeTimes[i-k+1]));
            }            
        }
        
        return false;
    }
};
