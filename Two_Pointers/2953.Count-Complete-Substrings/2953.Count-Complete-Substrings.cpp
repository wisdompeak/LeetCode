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
    
    bool check(vector<int>& freq, int k)
    {
        for (int x: freq)
        {
            if (x != k && x != 0) 
                return false;        
        }
        return true;
    }

    int helper(string s, int k)
    {
        int count = 0;
        set<char>Set(s.begin(), s.end());
        for (int T = 1; T <= Set.size(); T++) 
        {
            int length = T * k;            
            vector<int>freq(26,0);
            int start = 0;
            int end = start + length - 1;
            for (int i = start; i <= min(end, (int)s.size() - 1); i++) 
            {                
                freq[s[i]-'a']++;
            }
            while (end < s.size()) 
            {
                if (check(freq, k)) count++;
                freq[s[start]-'a']--;
                start++;
                end++;
                if (end < s.size()) freq[s[end]-'a']++;
            }
        }
        
        return count;
    }
};
