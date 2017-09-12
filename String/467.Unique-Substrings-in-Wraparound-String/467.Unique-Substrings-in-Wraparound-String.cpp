class Solution {
public:
    int findSubstringInWraproundString(string p) 
    {
        unordered_map<char,int>Map;
        for (int i=0; i<p.size(); i++)
        {
            int j=i;
            while (j+1<p.size() && (p[j+1]==p[j]+1 || p[j]=='z' && p[j+1]=='a'))
                j++;
            if (j-i+1>Map[p[i]])
                Map[p[i]]=j-i+1;            
        }
        
        int result=0;
        for (auto a:Map)
            result+=a.second;
        return result;
    }
};
