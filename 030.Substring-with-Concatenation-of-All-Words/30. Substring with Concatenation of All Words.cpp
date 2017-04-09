class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int>Map;
        int N=0;
        for (int i=0; i<words.size(); i++)
        {
            if (Map.find(words[i])==Map.end())
                N++;
            Map[words[i]]++;
        }
        
        int M=words[0].size();
        
        
        vector<int>results;
        
        for (int start=0; start<M; start++)
        {
            int i=start;
            int j=start;
            int count=0;
            unordered_map<string,int>Map_temp;
            
            while (j<s.size() && i<=j)
            {
                string ss = s.substr(j,M);
                
                if (Map.find(ss)==Map.end())
                {
                    j+=M;
                    i=j;
                    count=0;
                    Map_temp.clear();
                }
                else if (Map_temp[ss]<Map[ss])
                {
                    j+=M;
                    Map_temp[ss]++;
                    if (Map_temp[ss]==Map[ss])
                        count++;
                    
                    if (count==N)
                    {
                        results.push_back(i);
                        string tt = s.substr(i,M);
                        Map_temp[tt]--;
                        count--;
                        i+=M;
                    }
                }
                else
                {
                    string tt = s.substr(i,M);
                    Map_temp[tt]--;
                    if (Map_temp[tt]==Map[tt]-1)
                        count--;
                    i+=M;
                }
                
            }
        }
        
        return results;
        
        
    }
};
