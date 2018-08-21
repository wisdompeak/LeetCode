class Solution {
public:
    int kEmptySlots(vector<int> &flowers, int k) 
    {
        int N = flowers.size();
        vector<int>days(N);
        for (int i=0; i<N; i++)
            days[flowers[i]-1] = i;
        
        int result = INT_MAX;
        int candidate;
        for (int i=0; i<N; i++)
        {
            int left = i;
            int right = left+k+1;
            if (right>=N) break;
            
            bool flag = 1;
            for (int j=left+1; j<=right-1; j++)
            {
                if (days[j]<days[left] || days[j]<days[right])
                {
                    flag = 0;
                    i = j-1;
                    break;
                }
            }
            if (flag) 
            {
                candidate = max(days[left],days[right])+1;
                result = min(result,candidate);
            }
        }
        if (result==INT_MAX)
            return -1;
        else
            return result;
    }
};
