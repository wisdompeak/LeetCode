class Solution {
public:
    bool isTransformable(string s, string t) 
    {
        int n = s.size();
        vector<pair<int,int>>a(n);
        vector<pair<int,int>>b(n);

        for (int i=0; i<n; i++)
        {            
            a[i].first = s[i]-'0';
            a[i].second = i;
        }

        for (int i=0; i<n; i++)
        {
            b[i].first = t[i]-'0';
            b[i].second = i;
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        for (int i=0; i<n; i++)
        {
            if (a[i].first!=b[i].first)            
                return false;            
        }
        
        vector<int>leftLimit(n,0);
        
        for (int i=0; i<n; i++)
        {
            int ps = a[i].second;
            int pt = b[i].second;
            
            if (leftLimit[ps] > pt) 
                return false;
            
            for (int j=ps+1; j<n; j++)
            {
                if (s[j]-'0' > a[i].first)
                    leftLimit[j] = max(leftLimit[j], pt);                
            }
        }
        return true;
        
    }
};
