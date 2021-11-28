class Solution {
public:
    int minimumBuckets(string street) 
    {
        int n = street.size();
        int ret = 0;
        
        for (int i=0; i<n; i++)
        {
            if (street[i]!='H') continue;
            
            if (i-1>=0 && street[i-1]=='#')
            {
                continue;
            }
            else if (i+1<n && street[i+1]=='.')
            {
                street[i+1] = '#';
                ret++;
            }
            else if (i-1>=0 && street[i-1]=='.')
            {
                street[i-1] = '#';
                ret++;
            }            
            else
            {
                return -1;
            }            
        }
        
        return ret;        
    }
};
