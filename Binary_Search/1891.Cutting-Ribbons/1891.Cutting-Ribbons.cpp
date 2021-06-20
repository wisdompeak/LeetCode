class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) 
    {
        int left = 0, right = INT_MAX;
        while (left < right)
        {
            int len = right-(right-left)/2;
            if (count(ribbons, len) >= k)
                left = len;
            else
                right = len-1;
        }
        return left;        
    }
    
    int count(vector<int>&ribbons, int len)
    {
        int ret = 0;
        for (auto x: ribbons)
        {
            ret += x/len;
        }
        return ret;
    }
};
