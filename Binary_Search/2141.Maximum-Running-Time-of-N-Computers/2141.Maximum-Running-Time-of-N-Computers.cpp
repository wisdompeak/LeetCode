using LL = long long;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        LL left = 0, right = LLONG_MAX/n;
        while (left < right)
        {
            LL mid = right-(right-left)/2;
            if (checkOK(mid, n, batteries))
                left = mid;
            else
                right = mid-1;
        }
        return left;        
    }
    
    bool checkOK(LL T, LL n,  vector<int>& batteries)
    {
        LL sum = 0;
        for (auto x: batteries)
        {
            sum += min((LL)x, T);
            if (sum >= T*n)
                return true;
        }
        return false;
    }
};

