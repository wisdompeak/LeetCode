class Solution {
public:
    int findIntegers(int num) 
    {
        if (num==0) return 1;
        if (num==1) return 2;
        
        int n=0;
        string str;
        while (num>0)
        {
            n++;
            str+=to_string(num&1);
            num=num>>1;
        }
        reverse(str.begin(),str.end());
        
        vector<int>f(n+1);
        
        f[0]=1;
        f[1]=2;
        for (int i=2; i<=n; i++)
            f[i]=f[i-1]+f[i-2];
        
        int result=0;
        for (int i=0; i<str.size(); i++)
        {
            if (str[i]=='1')
            {
                result+=f[n-i-1];    
                if (i+1<str.size() && str[i+1]=='1') 
                    return result+f[n-i-2];
            }
        }
        
        result++;
        
        return result;
    }
    
};
