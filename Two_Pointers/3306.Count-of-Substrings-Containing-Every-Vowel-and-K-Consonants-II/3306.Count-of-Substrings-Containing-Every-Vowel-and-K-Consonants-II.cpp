class Solution {
public:
    long long countOfSubstrings(string word, int k) 
    {
        int count0 = 0;
        int count1 = 0;
        int n = word.size();
        
        unordered_set<char>Set({'a','e','i','o','u'});
        unordered_map<char,int>Map;        
        
        vector<int>consecutive(n);
        int c = 0;
        for (int i=n-1; i>=0; i--)
        {
            if (Set.find(word[i])==Set.end())
                c = 0;
            else
                c++;
            consecutive[i] = c;
        }
        
        long long ret = 0;
        int j = 0;
        for (int i=0; i<n; i++)
        {
            while (j<n && (count0<5 || count1<k))
            {
                if (Set.find(word[j])!=Set.end())                
                {
                    Map[word[j]]++;                
                    if (Map[word[j]]==1) count0++;     
                }
                else 
                    count1++;                                       
                j++;
            }
            if (count0==5 && count1==k)
            {
                ret += 1 + (j<n?consecutive[j]:0);
            }
            
            if (Set.find(word[i])!=Set.end())
            {
                Map[word[i]]--;                
                if (Map[word[i]]==0)
                    count0--;            
            }                
            else 
                count1--;
            
        }
        
        return ret;
    }
};
