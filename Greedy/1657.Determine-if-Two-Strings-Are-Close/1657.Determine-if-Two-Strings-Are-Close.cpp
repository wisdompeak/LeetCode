class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        unordered_set<char>Set1;
        unordered_set<char>Set2;

        vector<int>a(26,0);
        vector<int>b(26,0);
        for (auto ch:word1)
        {
            a[ch-'a']+=1;
            Set1.insert(ch);
        }            
        for (auto ch:word2)
        {
            b[ch-'a']+=1;
            Set2.insert(ch);
        }
            
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a==b && Set1==Set2;        
    }
};
