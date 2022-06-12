using LL = long long;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        vector<unordered_set<string>>head2str(26);
        for (string& idea: ideas)
            head2str[idea[0]-'a'].insert(idea.substr(1));
        
        LL ret = 0;
        for (int i=0; i<26; i++)
            for (int j=i+1; j<26; j++)
            {
                int dup = 0;
                for (string x: head2str[i])
                    if (head2str[j].find(x)!=head2str[j].end())
                        dup++;
                LL a = head2str[i].size() - dup;
                LL b = head2str[j].size() - dup;
                ret += a*b*2;                
            }
        
        return ret;
    }
};
