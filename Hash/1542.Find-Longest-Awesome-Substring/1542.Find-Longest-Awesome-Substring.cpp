class Solution {
public:
    int longestAwesome(string s) 
    {
        vector<int>count(10,0);
        int n = s.size();
        s="#"+s;
        
        unordered_map<int,int>Map;
        Map[0] = 0;
        int ret = 0;
        
        for (int i=1; i<=n; i++)
        {            
            count[s[i]-'0']+=1;
            int key = makeKey(count);
            
            if (Map.find(key)!=Map.end())
                ret = max(ret, i - Map[key]);
            
            for (int k=0; k<10; k++)
            {
                int newKey = key;
                
                if (((key>>k)&1)==0)
                    newKey |= (1<<k);
                else
                    newKey -= (1<<k);
                
                if (Map.find(newKey)!=Map.end())
                    ret = max(ret, i - Map[newKey]);                    
            }
            if (Map.find(key)==Map.end()) Map[key] = i;            
        }
        
        return ret;
    }
    
    int makeKey(vector<int>&count)
    {
        int key=0;
        for (int i=0; i<10; i++)
        {
            if (count[i]%2==0)
                key+=(0<<i);
            else
                key+=(1<<i);
        }
        return key;
    }
};
