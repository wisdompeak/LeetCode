class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long count = 0;
        long M = 1e9+7;
        for (int k=1; k<n-1; k++)
        {
            int j = n-1;
            for (int i = 0; i<k; i++)
            {
                int count1 = 1;
                int count2 = 0;
                while (i+1<k && arr[i+1]==arr[i])
                {
                    count1++;
                    i++;
                }
                
                while (j>k && arr[i]+arr[k]+arr[j]>target)
                    j--;                
                while (j>k && arr[i]+arr[k]+arr[j]==target)
                {
                    count2++;                    
                    j--;
                }            
                count += count1*count2;
                count %= M;                
            }
        }
        return count;
        
    }
};
