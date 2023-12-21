class Solution {
public:
    int countCompleteSubstrings(string word, int k) 
    {
        int n = word.size();
        int ret = 0;
        for (int i=0; i<n; )
        {
            int j = i+1;
            while (j<n && abs(word[j]-word[j-1])<=2)
                j++;
            ret += helper(word.substr(i, j-i), k);
            i = j;
        }
        return ret;        
    }
    
    int helper(string s, int k)
    {
        int count = 0;
        set<char>Set(s.begin(), s.end());
        for (int T = 1; T <= Set.size(); T++) 
        {
            int len = T * k;            
            vector<int>freq(26,0);
            int j = 0;
            for (int i=0; i+len-1<s.size(); i++)
            {
                while (j<=i+len-1)
                {
                    freq[s[j]-'a']++;
                    j++;
                }                    
                if (check(freq, k)) count++;
                freq[s[i]-'a']--;
            }
        }
        
        return count;
    }

        bool check(vector<int>& freq, int k)
    {
        for (int x: freq)
        {
            if (x != k && x != 0) 
                return false;        
        }
        return true;
    }
};
