class Solution {
public:
    vector<string> generateAbbreviations(string word) 
    {
        int n = word.size();
        vector<string>rets;
        for (int state = 0; state < (1<<n); state++)
        {
            string s;
            for (int i=0; i<n; i++)
            {
                if ((state>>i)&1)
                {
                    s.push_back(word[i]);
                }
                else
                {
                    int j = i;
                    while (j<n && ((state>>j)&1)==0)
                        j++;
                    s += to_string(j-i);                    
                    i = j-1;
                }
            }
            rets.push_back(s);
        }
        return rets;
    }
};
