class Solution {
    long long M = pow(10,9)+7;
public:
    int uniqueLetterString(string S) 
    {        
        vector<vector<int>>pos(26);
        int result=0;
        for (int i=0; i<S.size(); i++)
        {
            pos[S[i]-'A'].push_back(i);
            for (int i=0; i<26; i++)
            {
                if (pos[i].size()==1)
                    result+=pos[i][0]+1;
                else if (pos[i].size()>1)
                {
                    int k = pos[i].size();
                    result+=pos[i][k-1]-pos[i][k-2];
                }
                result = result%M;    
            }
        }
        return result;
    }
    
};
