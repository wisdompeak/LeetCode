class Solution {
    unordered_map<string,int>mem;
    unordered_map<string,int>mem1;
public:
    int minimumOneBitOperations(int n) 
    {
        string str = bitset<32>(n).to_string();
        return dfs(str);        
    }
    
    int dfs(string n)
    {    
        if (n=="0") return 0;
        if (n=="1") return 1;
        if (mem.find(n)!=mem.end()) return mem[n];
        
        if (n[0]=='0') return dfs(n.substr(1));
        
        string m = n.substr(1);
        string p = m;
        p[0] = '1';
        for (int i=1; i<p.size(); i++)
            p[i] = '0';                        
        mem[n] = dfs1(m) + 1 + dfs(p);
        return mem[n];
    }
    
    int dfs1(string n)
    {
        if (n=="0") return 1;
        if (n=="1") return 0;
        if (mem1.find(n)!=mem1.end()) return mem1[n];
                
        if (n[0]=='1')
            mem1[n] = dfs(n.substr(1));
        else
        {
            string m = n.substr(1);
            string p = m;
            p[0] = '1';
            for (int i=1; i<p.size(); i++)
                p[i] = '0';            
            mem1[n] = dfs1(m)+1 + dfs(p);            
        }
        return mem1[n];        
    }
    
};
