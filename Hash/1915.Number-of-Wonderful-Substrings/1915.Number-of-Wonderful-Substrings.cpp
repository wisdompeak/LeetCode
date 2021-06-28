typedef long long ll;
class Solution {
public:
    long long wonderfulSubstrings(string word) 
    {
        int n = word.size();
        int state = 0;
        vector<int>count(1<<10);
        count[0]+=1;
        
        ll ret = 0;
        for (int i=0; i<n; i++)
        {
            int j = word[i]-'a';
            state ^= (1<<j);
            
            ret += count[state];
            
            for (int j=0; j<10; j++)            
                ret += count[state ^ (1<<j)];                                

            count[state]++;
        }
        return ret;
    }
};
