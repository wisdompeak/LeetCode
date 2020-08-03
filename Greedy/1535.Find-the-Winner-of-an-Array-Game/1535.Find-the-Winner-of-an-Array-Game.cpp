class Solution {
public:
    int getWinner(vector<int>& arr, int k) 
    {
        int curMax = arr[0];
        int times = 0;
        for (int i=1; i<arr.size(); i++)
        {
            if (arr[i]>curMax)
            {
                curMax = arr[i];
                times = 1;
            }
            else
            {
                times+=1;
            }
            if (times == k) return curMax;
        }
        return curMax;
    }
};
