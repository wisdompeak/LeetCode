class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int count = 0;
        int cur = 1;
        for (auto x: arr)
        {
            while (x > cur && count <k)
            {
                count++;
                cur++;
            }
            if (count==k) return cur-1;            
            if (x==cur) cur++;
        }
        return cur-1+(k-count);
        
    }
};
