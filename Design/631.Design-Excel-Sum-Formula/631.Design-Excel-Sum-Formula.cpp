class Excel {    
    int Val[27][26];
    vector<string> Exp[27][26];
public:
    Excel(int H, char W) 
    {                
        for (int i=0; i<27; i++)
            for (int j=0; j<26; j++)
                Val[i][j] = 0;
    }
    
    void set(int r, char c, int v) 
    {        
        Val[r][c-'A']=v;
        Exp[r][c-'A'].clear();
    }
    
    int get(int r, char c) 
    {
        if (Exp[r][c-'A'].empty())
            return Val[r][c-'A'];
        else
        {
            int ret = 0;
            for (auto s: Exp[r][c-'A'])
            {
                int p = s.find(":");
                if (p==-1)
                {
                    auto [x, y] = parse(s);
                    ret += get(x, y);
                }
                else
                {
                    auto [x0, y0] = parse(s.substr(0, p));
                    auto [x1, y1] = parse(s.substr(p+1));
                    for (int i=x0; i<=x1; i++)
                        for (char j=y0; j<=y1; j++)
                            ret += get(i, j);
                }
            }
            return ret;
        }
            
    }
    
    int sum(int r, char c, vector<string> strs) 
    {
        Exp[r][c-'A'] = strs;
        return get(r,c);
    }
    
    pair<int, char> parse(string s)
    {        
        int num = stoi(s.substr(1));
        char ch = s[0];
        return {num, ch};
    }
    
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
