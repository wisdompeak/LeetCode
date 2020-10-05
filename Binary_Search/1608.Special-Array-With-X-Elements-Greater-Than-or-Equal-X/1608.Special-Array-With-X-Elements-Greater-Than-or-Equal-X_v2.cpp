class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        int N = nums.size();
        vector<int>freq(N+1,0);
        for (auto x: nums)
            freq[min(x,N)]+=1;

        int count = 0;
        for (int x=N; x>=0; x--)
        {
            count+=freq[x];                
            if (count == x)
                return x;
        }
        return -1;
    }
};
