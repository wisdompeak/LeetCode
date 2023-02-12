class Solution {
public:
    int minimumScore(string s, string t) 
    {
        int m = s.size();
        int n = t.size();
        
        vector<int>left(n, m);
        int j = 0;
        for (int i=0; i<n; i++)
        {
            while (j<m && s[j]!=t[i])
                j++;
            if (j<m)
            {
                left[i] = j;
                j++;
            }                
        }
        
        vector<int>right(n, -1);
        j = m-1;
        for (int i=n-1; i>=0; i--)
        {
            while (j>=0 && s[j]!=t[i])
                j--;
            if (j>=0)
            {
                right[i] = j;
                j--;
            }                
        }
                
        int low = 0, high = n;
        while (low < high)
        {
            int mid = low+(high-low)/2;
            if (isOK(mid, s, t, left, right))
                high = mid;
            else
                low = mid+1;
        }
        
        return low;        
    }
    
    bool isOK(int len, string& s, string& t, vector<int>&left, vector<int>&right)
    {
        int m = s.size();
        int n = t.size();
        
        if (right[len]>=0) return true;
        if (left[n-len-1] < m) return true;
        
        for (int i=1; i+len<n; i++)
        {
            if (left[i-1] < right[i+len])
                return true;
        }
        return false;        
    }
    
};
