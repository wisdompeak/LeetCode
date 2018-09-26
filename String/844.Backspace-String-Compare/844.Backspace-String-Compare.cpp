class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {        
        int i = squeeze(S);        
        int j = squeeze(T);
        
        return S.substr(i)==T.substr(j);
    }
    
    int squeeze(string& S)
    {
        int i = S.size()-1;
        int j = S.size()-1;
        int count = 0;
        
        while (i>=0)
        {
            while (count>0 || i>=0 && S[i]=='#')
            {
                if (S[i]=='#')
                    count++;
                else
                    count--;
                i--;
            }
            if (i>=0)
            {
                S[j] = S[i];
                j--;
                i--;
            }            
        }
        return j+1;
    }
};
