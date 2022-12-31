using LL = long long;
LL M = 1e9+7;
class Solution {
    LL inv[100005];
public:
    int countAnagrams(string s) 
    {
        vector<string>str_arr;
        istringstream in(s);
        int k = 0;
        for (string word; in>>word; k++) 
            str_arr.push_back(word);    
                
        inv[1] = 1;
        for(int i=2; i<=100000; ++i)
            inv[i]=(M-M/i) * inv[M%i] % M;
        
        LL ret = 1;
        for (auto& str: str_arr)
        {
            ret = ret * helper(str) % M;
        }
        return ret;
    }
    
    LL helper(string& s)
    {
        unordered_map<int,int>Map;
        for (auto ch: s)
            Map[ch]+=1;
        
        int N = s.size();
        LL ret = 1;
        for (int i=1; i<=N; i++)
            ret = ret * i % M;
        
        for (auto [k,v]:Map)
        {
            for (int i=1; i<=v; i++)
                ret = ret * inv[i] % M;
        }
        return ret;
    }
};
