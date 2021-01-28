class Solution {
    int Father[26];
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y)
            Father[y] = x;
        else
            Father[x] = y;
    }
public:
    string smallestEquivalentString(string A, string B, string S) 
    {
        for (int i=0; i<26; i++)
            Father[i] = i;
        
        for (int i=0; i<A.size(); i++)
        {
            if (FindFather(A[i]-'a')!=FindFather(B[i]-'a'))
                Union(A[i]-'a', B[i]-'a');
        }
        
        
        string ret;
        for (auto ch: S)
            ret.push_back('a'+FindFather(ch-'a'));
        
        return ret;
    }
};
