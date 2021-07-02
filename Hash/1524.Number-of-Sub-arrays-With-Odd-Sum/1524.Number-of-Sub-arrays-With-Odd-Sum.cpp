class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int presum = 0;
        long odd = 0, even  = 1;
        long ret = 0;
        long M = 1e9+7;
        for (int x : arr)
        {
            presum+=x;
            if (presum%2==0)
                ret = (ret+odd)%M;
            else
                ret = (ret+even)%M;
            if (presum%2==0)
                even+=1;
            else
                odd+=1;
        }
        return ret;

    }
};
