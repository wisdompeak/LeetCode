class Solution {
public:
    string getPermutation(int n, int k) 
    {
        string nums;
        for (int i=1; i<=9; i++)
            nums+=to_string(i);
        string result;
        
        k=k-1;
        
        while (n>0)
        {
            int N=1;
            for (int i=1; i<=n-1; i++)
                N=N*i;
            
            int a=k/N;
            result+=nums[a];
            
            k=k-a*N;
            n--;            
            nums.erase(a,1);
        }
        
        return result;
    }
};
