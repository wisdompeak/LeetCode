class Solution {
public:            
    unordered_map<char,char>Map={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
    int count = 0;    
    int N;
    string n;
    
    long perm(int l)
    {
        return 4*pow(5,l-1);
    }
    
    long symmetric(int l)
    {
        if (l%2==0)        
            return 4*pow(5,l/2-1);
        else
            return 4*pow(5,l/2-1)*3;
    }
    
    int confusingNumberII(int N) 
    {        
        this->N = N;
        n = to_string(N);
        
        for (int l=1; l<n.size(); l++)
        {
            count += perm(l) - symmetric(l);
        }
        
        for (long x: {1,6,8,9})
            dfs(x,1);
        return count;
    }
    
    void dfs(long num, int k)
    {
        if (k==n.size())
        {
            if (num>N) return;
            if (isConfusing(num)) count++;
            return;
        }
            
        for (auto x:{0,1,6,8,9})        
            dfs(num*10+x, k+1);
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
