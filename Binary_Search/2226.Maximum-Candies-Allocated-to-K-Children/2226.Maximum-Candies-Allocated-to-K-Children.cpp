using LL = long long;
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) 
    {
        LL total = 0;
        for (auto x: candies)
            total += (LL)x;
        
        LL left= 0, right = total/k;        
        while (left < right)
        {
            LL mid = right - (right - left) / 2;                        
            if (checkOK(candies, mid, k))
                left = mid;
            else
                right = mid-1;            
        }        
        return left;
    }
    
    bool checkOK(vector<int>& candies, LL numPerPile, LL k)
    {
        LL count = 0;
        for (LL x: candies)
        {
            count += x / numPerPile;
            if (count >= k)
                return true;
        }
        return false;
    }
};
