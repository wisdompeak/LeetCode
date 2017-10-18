class Solution {
public:
    int integerReplacement(int n) 
    {
        return DFS(n);
    }
    
    long long DFS(long long n) 
    {
        if (n==1) return 0;
        
        if (n%2==0)
            return DFS(n/2)+1;
        else
            return min(DFS(n+1),DFS(n-1))+1;
    }
};
