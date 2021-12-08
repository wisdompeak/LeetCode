class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int left = 1, right = INT_MAX/2;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (checkOK(quantities, n, mid))            
                right = mid;                            
            else
                left = mid+1;                
        }
        return left;
    }
    
    bool checkOK(vector<int>& quantities, int n, int limit)
    {
        int count = 0;
        for (int x: quantities)
        {
            if (x%limit == 0)
                count += x/limit;
            else
                count += x/limit+1;
        }
        return count <=n;
    }
};
