class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        vector<int>count(value);
        
        for (int& x: nums)
        {
            x = ((x%value)+value) % value;
            count[x] += 1;
        }
        
        int min_count = INT_MAX;
        int k;
        
        for (int i=0; i<value; i++)
        {
            if (count[i]<min_count)
            {
                min_count = count[i];
                k = i;
            }            
        }
        
        return min_count*value + k;        
    }
};
