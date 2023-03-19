using LL = long long;
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        LL left = 0, right = LLONG_MAX;
        while (left < right)
        {
            LL mid = left + (right-left)/2;
            if (isOK(mid, ranks, cars))
                right = mid;
            else
                left = mid+1;
        }
        return left;        
    }
    
    bool isOK(LL t, vector<int>& ranks, int cars)
    {
        LL count = 0;
        for (int r : ranks)
        {
            count += sqrt(t/r);
            if (count >= cars)
                return true;
        }
        return false;
        
    }
};
