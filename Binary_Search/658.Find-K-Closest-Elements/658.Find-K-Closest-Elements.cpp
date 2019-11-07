class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int low = 0;
        int hi = arr.size()-k;
        
        while (low<hi)
        {
            int mid = low+(hi-low)/2;
            
            if (x - arr[mid] > arr[mid+k] - x)
                low = mid+1;
            else
                hi = mid;
        }
        
        vector<int>ret;
        for (int i=low; i<low+k; i++)
            ret.push_back(arr[i]);
        
        return ret;
    }
};
