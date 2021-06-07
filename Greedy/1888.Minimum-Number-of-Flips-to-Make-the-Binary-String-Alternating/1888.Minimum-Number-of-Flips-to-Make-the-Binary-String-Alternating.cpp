class Solution {
public:
    int minFlips(string s) 
    {
        int n = s.size();
        
        vector<int>left0(n);
        vector<int>left1(n);
        vector<int>right0(n);
        vector<int>right1(n);
        
        int sumLeft0 = 0, sumLeft1 = 0;
        for (int i=0; i<n; i++)
        {
            if (i%2==0 && s[i]=='1' || i%2==1 && s[i]=='0')
                sumLeft0++;
            if (i%2==0 && s[i]=='0' || i%2==1 && s[i]=='1')
                sumLeft1++;
            left0[i] = sumLeft0;
            left1[i] = sumLeft1;
        }
        
        int sumRight0 = 0, sumRight1 = 0;
        for (int i=n-1; i>=0; i--)
        {
            int j = n-1-i;
            if (j%2==0 && s[i]=='1' || j%2==1 && s[i]=='0')
                sumRight0++;
            if (j%2==0 && s[i]=='0' || j%2==1 && s[i]=='1')
                sumRight1++;
            right0[i] = sumRight0;
            right1[i] = sumRight1;
        }
        
        int ret = n;
        ret = min(ret, sumLeft0);
        ret = min(ret, sumLeft1);
        ret = min(ret, sumRight0);
        ret = min(ret, sumRight1);
        
        for (int i=0; i<n-1; i++)
        {
            ret = min(ret, left0[i]+right1[i+1]);
            ret = min(ret, left1[i]+right0[i+1]);
        }
        
        return ret;
    }
};
