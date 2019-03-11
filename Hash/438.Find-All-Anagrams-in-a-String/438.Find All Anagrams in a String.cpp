class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>P(255,0);
        vector<int>S(255,0);
        for (char ch:p) P[ch]++;
        
        vector<int>results;
        for (int i=0; i<s.size(); i++)
        {
            S[s[i]]++;
            if (i>=p.size()) S[s[i-p.size()]]--;            
            if (S==P) results.push_back(i-p.size()+1);
        }
        return results;
    }
};
