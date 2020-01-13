class Solution {
public:            
    unordered_map<char,char>Map;
    unordered_set<int>candidates;
    int count = 0;
    int N;
    
    int confusingNumberII(int N) 
    {
        candidates={0,1,6,8,9};
        Map={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        
        this->N = N;
        for (auto x: {1,6,8,9})
            dfs(x);
        return count;
    }
    
    void dfs(long num)
    {
        if (num>N) return;                
        
        if (isConfusing(num)) count++;
            
        for (auto x:candidates)        
            dfs(num*10+x);
    }
    
    bool isConfusing(int num)
    {
        string s = to_string(num);
        int i=0;
        int j=s.size()-1;
        while (i<=j)
        {
            if (Map[s[i]]!=s[j])
                return true;
            i++;
            j--;
        }                
        return false;
    }
};
