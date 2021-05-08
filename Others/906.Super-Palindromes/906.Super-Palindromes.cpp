class Solution {
public:
    int superpalindromesInRange(string L, string R) 
    {
        long long a = stoll(L);
        long long b = stoll(R);
               
        int start = pow(10, max(0, (int)L.size()/4-1));
        int end = pow(10, max(0, (int)R.size()/4+1));
        
        int count = 0;
        
        for (int i=start; i<=end; i++)
        {
            for (int type = 0; type<=1; type++)
            {
                long long palin = constructPalin(i, type);
                if (palin>1e9) continue;                
                
                long long superPalin = palin*palin;
                if (superPalin>=a && superPalin<=b && isPalin(superPalin))
                    count++;
            }
        }
        
        return count;
    }
    
    long long constructPalin(long long x, int type)
    {
        long long y = x;
        if (type==1) x/=10;
        while (x>0)
        {
            y = y*10 + x%10;
            x = x/10;
        }
        return y;        
    }
    
    bool isPalin(long long x)
    {
        string s = to_string(x);
        string t = s;
        reverse(t.begin(),t.end());
        return s==t;
    }
};
