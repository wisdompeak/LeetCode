class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) 
    {
        int sum = 0;
        for (auto x: sweetness)
            sum+=x;
        
        int left = 0;
        int right = sum;
        
        while (left<right)
        {
            int mid = left+(right-left+1)/2;
            if (ok(sweetness, mid, K))
                left = mid;
            else
                right = mid-1;
        }
        
        return left;
    }
    
    bool ok(vector<int>& sweetness, int S, int K)
    {
        int sum = 0;
        int count = 0;
        for (int i=0; i<sweetness.size(); i++)
        {
            sum+=sweetness[i];
            if (sum>=S)
            {
                sum = 0;
                count++;
            }
        }
        return count>=K+1;
    }
};
