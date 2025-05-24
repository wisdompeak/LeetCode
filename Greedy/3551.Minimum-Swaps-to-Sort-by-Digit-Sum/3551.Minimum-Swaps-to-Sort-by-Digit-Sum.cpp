class Solution {
public:
    int helper(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        unordered_map<int, int>expected;
        for (int i=0; i<n; i++)
            expected[B[i]] = i;

        int count = 0;
        for (int i=0; i<n; i++)
        {
            while (expected[A[i]]!=i)
            {
                swap(A[i], A[expected[A[i]]]);
                count++;
            }
        }        

        return count;
    }
    int minSwaps(vector<int>& nums) 
    {
        vector<vector<int>>arr;
        int n = nums.size();
        for (int i=0; i<n; i++)
        {
            int sum = 0;
            int x = nums[i];
            while (x>0)
            {
                sum += x%10;
                x/=10;
            }
            arr.push_back({sum, nums[i], i});
        }
        
        sort(arr.begin(), arr.end());
        
        vector<int>A(n);        
        vector<int>B(n);
        for (int i=0; i<n; i++)
        {
            A[i] = i;
            B[i] = arr[i][2];
        }
                   
        return helper(A, B);
        
    }
};
