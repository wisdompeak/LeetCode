class Solution {
public:
    string orderlyQueue(string S, int K) 
    {
        if (K>=2)
        {
            sort(S.begin(),S.end());
            return S;
        }
        
        string ret = S;
        for (int i=0; i<S.size(); i++)
        {
            S = S.substr(1) + S.substr(0,1);
            if (S<ret)
                ret = S;
        }
        return ret;
    }
};
