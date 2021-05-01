class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        
        for (int i=1; i<arr.size(); i++)
        {
            if (arr[i]>arr[i-1]+1)
            {
                arr[i] = arr[i-1]+1;                
            }
                
        }
        
        for (int i=arr.size()-2; i>=0; i--)
        {
            if (arr[i]>arr[i+1]+1)
            {
                arr[i] = arr[i+1]+1;
            }
        }
        
        int ret = 0;
        for (auto x: arr)
            ret = max(ret, x);
        return ret;
    }
};
