class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        auto expect = arr;
        sort(expect.begin(), expect.end());

        long sum1=0, sum2=0, count=0;
        for (int i=0; i<arr.size(); i++)
        {
            sum1+=arr[i];
            sum2+=expect[i];
            if (sum1==sum2)
            {
                count += 1;
                sum1 = 0, sum2 = 0;
            }
        }
        return count;
    }
};
