class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        auto table = vector<vector<int>>(26);
        for (int i=0; i<S.size(); i++)
            table[S[i]-'a'].push_back(i);
        
        int count = 0;
        for (auto str:words)
        {
            if (str.size()>S.size()) continue;
            if (check(str,table)) count++;
        }
            
        return count;
    }
    
    bool check(string A, vector<vector<int>>&table)
    {
        int i=0;
        for (char ch:A)
        {
            auto iter = lower_bound(table[ch-'a'].begin(),table[ch-'a'].end(),i);
            if (iter==table[ch-'a'].end()) return false;
            i = *iter+1;
        }
        return true;
    }
};
