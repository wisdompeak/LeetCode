class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>Map(128,0);
        vector<int>Table(128,0);
        
        int N=p.size();

        for (int i=0; i<N; i++)
            Map[p[i]]++;
        
        for (int i=0; i<N; i++)
            Table[s[i]]++;

        vector<int>result;
        if (s.size()<p.size()) return result;
        
        int i=N;
        while (i<s.size())
        {

            if (Table==Map)
                result.push_back(i-N);
            
            Table[s[i-N]]--;
            Table[s[i]]++;
            i++;
        }
        
        if (Table==Map)
            result.push_back(i-N);
        
        return result;
    }
};
