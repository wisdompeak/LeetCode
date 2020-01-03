class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) 
    {
        vector<int> rets;
        
        int count = 0;
        for (auto x: A)
            if (x==1) count++;
        if (count%3!=0) return {-1,-1};
        if (count==0) return {0,A.size()-1};
        count/=3;
        
        int j = A.size();
        while (count)
        {
            j--;
            if (A[j]==1) count--;
        }
        
        int i = 0;
        while (A[i]==0) i++;
        int k = j;
        while (k<A.size() && A[i]==A[k])
        {
            i++;
            k++;
        }
        if (k!=A.size()) return {-1,-1};
        rets.push_back(i-1);
        
        while (A[i]==0) i++;
        k = j;
        while (k<A.size() && A[i]==A[k])
        {
            i++;
            k++;
        }
        if (k!=A.size()) return {-1,-1};
        rets.push_back(i);
        
        return rets;
    }
};
