class Solution {
public:
    int numWays(string s) 
    {
        long ret = 0;
        long M = 1e9+7;

        unordered_map<int,int>Map;     
        int count = 0;   
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]=='1') 
            {
                count++;
                Map[count] = i;
            }
        }            
        if (count%3!=0) return 0;
        long n = s.size();
        if (count==0) return (n-1)*(n-2)/2%M;

        long x = Map[count/3+1] - Map[count/3];
        long y = Map[count/3*2+1] - Map[count/3*2];
        return x*y%M;
    }
};
