class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        if (n<m*k) return -1;
        
        int left = 0;
        int right = INT_MAX;
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (isOK(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
        
    }
    
    bool isOK(vector<int>& bloomDay, int m, int k, int t)
    {
        int cnt = 0;
        int cur = 0;
        for (int i=0; i<bloomDay.size(); i++)
        {
            if (bloomDay[i] > t)
            {
                cur = 0;
            }
            else 
            {
                cur += 1;
                if (cur==k)
                {
                    cur = 0;
                    cnt += 1;
                }
            }
            if (cnt >=m ) return true;
        }
        return false;
    }
};
