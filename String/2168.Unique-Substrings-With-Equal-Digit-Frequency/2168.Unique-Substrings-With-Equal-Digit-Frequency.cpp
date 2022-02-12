using LL = long long;
LL M = 1e9+7;
class Solution {
public:
    int equalDigitFrequency(string s) 
    {
        vector<int>count(10);
        unordered_set<LL>Set;
        
        int n = s.size();
        for (int i=0; i<n; i++)
        {
            count.assign(10, -1);
            LL hash = 0;
            
            for (int j=i; j<n; j++)
            {
                hash = hash*11+(s[j]-'0'+1);
                hash = hash%M;
                
                count[s[j]-'0']++;
                
                int freq = -1;
                int flag = 1;
                for (int k=0; k<10; k++)
                {
                    if (count[k]==-1) continue;
                    if (freq==-1)
                        freq = count[k];
                    else if (freq!=count[k])
                    {
                        flag = 0;
                        break;                        
                    }                        
                }                
                if (flag) Set.insert(hash);
            }
        }
        
        return Set.size();
    }
};
