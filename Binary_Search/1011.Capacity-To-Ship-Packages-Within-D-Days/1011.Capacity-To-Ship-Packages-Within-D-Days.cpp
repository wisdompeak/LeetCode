class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) 
    {
        int left = INT_MAX;
        int right = 0;
        for (auto x:weights)
        {
            left = min(left, x);
            right += x;
        }
        
        while (left<right)
        {
            int cap = left+(right-left)/2;
            if (checkOK(weights,cap,D))
                right = cap;
            else
                left = cap+1;
        }
        
        return left;
        
    }
    
    bool checkOK(vector<int>& weights, int cap, int D)
    {
        int count = 0;
        for (int i=0; i<weights.size(); )
        {
            int j = i;
            int sum = 0;
            while (j<weights.size() && sum+weights[j]<=cap)
            {
                sum+=weights[j];
                j++;
            }
            count+=1;
            if (count>D) return false;
            i = j;
        }
        return true;        
    }
};

