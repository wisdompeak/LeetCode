class Solution {
public:
    int checkRecord(int n) 
    {
        long long a0l0=1,a0l1=1,a0l2=0,a1l0=1,a1l1=0,a1l2=0;
        long long M=1e9+7;
        
        for (int i=1; i<n; i++)
        {
            long long a0l0_temp=a0l0;
            long long a0l1_temp=a0l1;
            long long a0l2_temp=a0l2;
            long long a1l0_temp=a1l0;
            long long a1l1_temp=a1l1;
            long long a1l2_temp=a1l2;
            
            a0l0=(a0l0_temp+a0l1_temp+a0l2_temp)%M;
            a0l1=a0l0_temp;
            a0l2=a0l1_temp;
            a1l0=(a0l0_temp+a0l1_temp+a0l2_temp+a1l0_temp+a1l1_temp+a1l2_temp)%M;
            a1l1=a1l0_temp;
            a1l2=a1l1_temp;            
        }
        
        return (a0l0+a0l1+a0l2+a1l0+a1l1+a1l2)%M;
    }
};
