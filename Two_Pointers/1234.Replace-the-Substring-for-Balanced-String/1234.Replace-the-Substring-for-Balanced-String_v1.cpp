class Solution {
public:
    int balancedString(string s) 
    {
        int n = s.size();
        
        vector<int>sum(4,0);
        for (auto ch:s)
        {
            if (ch=='Q')
                sum[0]++;
            else if (ch=='W')
                sum[1]++;
            else if (ch=='E')
                sum[2]++;
            else
                sum[3]++;
        }
        
        if (sum[0]==sum[1] && sum[1]==sum[2]&&sum[2]==sum[3])
            return 0;
        
        int left = 1; 
        int right = n-1;
        
                
        while (left<right)
        {
            int mid = left+(right-left)/2;
                        
            if (work(s, sum, mid))
                right = mid;
            else
                left = mid+1;
        }
        
        if (left==right && work(s,sum,left))
            return left;
        else
            return n;
        
    }
    
    bool work(string &s, vector<int>sum, int len )
    {
        
        for (int i=0; i<s.size(); i++)
        {            
            if (s[i]=='Q')
                sum[0]--;
            else if (s[i]=='W')
                sum[1]--;
            else if (s[i]=='E')
                sum[2]--;
            else
                sum[3]--;
            
            if (i<len-1) continue;
            
            int k = max(max(max(sum[0],sum[1]),sum[2]),sum[3]);
            int total = k*4- sum[0]-sum[1]-sum[2]-sum[3];
            
            if (total<=len)
                return true;
            
            if (s[i-len+1]=='Q')
                sum[0]++;
            else if (s[i-len+1]=='W')
                sum[1]++;
            else if (s[i-len+1]=='E')
                sum[2]++;
            else
                sum[3]++;
            
        }
        
        return false;
    }
};
