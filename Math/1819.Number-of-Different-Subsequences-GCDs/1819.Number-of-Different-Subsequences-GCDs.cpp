class Solution {
    int Map[200001];
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) 
    {
        
        for (auto x: nums)
        {
            for (int i=1; i<=sqrt(x); i++)
            {
                if (x%i==0)
                {
                    int y = i;
                    if (Map[y]==0)
                        Map[y] = x;
                    else
                        Map[y] = gcd(Map[y], x);
                    
                    y = x/i;
                    
                    if (Map[y]==0)
                        Map[y] = x;
                    else
                        Map[y] = gcd(Map[y], x);                    
                }

            }
        }
        int count = 0;
        for (int i=1; i<=200000; i++)
            if (i == Map[i])
                count++;
                
        return count;        
    }    
};
