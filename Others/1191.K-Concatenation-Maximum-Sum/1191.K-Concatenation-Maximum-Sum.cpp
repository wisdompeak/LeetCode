class Solution {
    long M = 1e9+7;
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) 
    {   
        if (k==1)
            return maxSubArrSum(arr)%M; 
        
        long arrSum = 0; 
        for (int i = 0; i < arr.size(); i++) 
        {
            arrSum += arr[i]; 
            arrSum %= M;
        }            
         
        int len = arr.size();
        for (int i=0; i<len; i++)
            arr.push_back(arr[i]);
        
        if (arrSum < 0)                     
            return maxSubArrSum(arr)%M;         
        else        
            return (maxSubArrSum(arr) + ((long)k - 2) * arrSum % M)%M;               
    }
    
    long maxSubArrSum(vector<int>arr) 
    { 
        long max_so_far = 0; 
        long max_ending_here = 0; 
  
        for (int i = 0; i < arr.size(); i++) 
        { 
            max_ending_here = max_ending_here + arr[i]; 
            max_ending_here %= M;
            if (max_ending_here < 0) 
                max_ending_here = 0; 
            if (max_so_far < max_ending_here) 
                max_so_far = max_ending_here;
        } 
        return max_so_far; 
    } 
};
