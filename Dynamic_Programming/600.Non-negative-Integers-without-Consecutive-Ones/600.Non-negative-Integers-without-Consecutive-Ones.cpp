class Solution {
public:
    int findIntegers(int num) 
    {        
        if (num==0) return 0;
        if (num==1) return 2;
        
        vector<int>f(33);
        f[0]=1;
        f[1]=2;
        for (int i=2; i<32; i++)        
            f[i]=f[i-2]+f[i-1];        
        
        vector<int>digits(32,0);
        for (int i=0; i<32; i++)    
            digits[i]=((num>>i)&1);   
        
        int count=0;
        for (int i=31; i>=0; i--)
        {
            if (digits[i]==0) continue;
            
            // 第i位取0
            count+=f[i-1+1];  
            
            // 第i位取1
            if (i-1>=0 && digits[i-1]==1)
            {
                count+=f[i-2+1];
                return count;
            }
        }
        
        count++;
        
        return count;
        
    }
};
