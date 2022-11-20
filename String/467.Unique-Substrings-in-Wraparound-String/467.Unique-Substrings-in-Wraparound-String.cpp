class Solution {
public:
    int findSubstringInWraproundString(string p) 
    {
        unordered_map<char,int>Map;
        
        for (int i=0; i<p.size(); i++)
        {
            int i0=i;
            while (i+1<p.size() && (p[i+1]==p[i]+1 || p[i]=='z' && p[i+1]=='a'))
                i++;
            for (int k=i0; k<=i; k++)            
                Map[p[k]]=max(Map[p[k]],i-k+1);            
        }
        
        int count=0;        
        for (auto a:Map)
            count+=a.second;
        
        return count;
    }
};
