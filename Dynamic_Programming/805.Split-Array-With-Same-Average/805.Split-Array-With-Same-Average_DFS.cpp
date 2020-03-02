class Solution {
    double avg;
public:
    bool splitArraySameAverage(vector<int>& A) 
    {
        sort(A.begin(),A.end());
        int sum = accumulate(A.begin(), A.end(), 0);
        int n = A.size();
        
        for (int cnt = 1; cnt <= n/2; cnt++)
        {
            if (sum*cnt%n!=0) continue;
            if (DFS(A,cnt,sum*cnt/n,0))
                return true;
        }
        
        return false;
    }
    
    bool DFS(vector<int>&A, int cnt, int total, int idx)
    {
        if (total==0 && cnt==0) return true;
        
        if (idx==A.size()) return false;
                       
        if (cnt==0 || total ==0) return false;
        
        if (DFS(A, cnt-1, total-A[idx], idx+1)) return true;
        
        int i = idx;
        while (i<A.size() && A[i]==A[idx])
            i++;        
        if (i<A.size() && DFS(A, cnt, total, i)) return true;       
        
        return false;
    }
};
