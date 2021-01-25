class Solution {
public:
    int minCharacters(string a, string b) 
    {
        vector<int>countA(26);
        vector<int>countB(26);
        for (auto ch: a)
            countA[ch-'a']+=1;
        for (auto ch: b)
            countB[ch-'a']+=1;

        int ret = INT_MAX;
        for (int th = 0; th < 26; th++)
        {
            if (th>0)
            {
                int change = 0;
                for (int i=0; i<th; i++)
                    change+=countA[i];
                for (int i=th; i<26; i++)
                    change+=countB[i];
                ret = min(ret, change);

                change = 0;
                for (int i=0; i<th; i++)
                    change+=countB[i];
                for (int i=th; i<26; i++)
                    change+=countA[i];
                ret = min(ret, change);
            }
            
            int change = 0;
            for (int i=0; i<26; i++)
                if (i!=th)
                {
                    change += countA[i];
                    change += countB[i];
                }
            ret = min(ret, change);                        
        }
        return ret;
    }
};
