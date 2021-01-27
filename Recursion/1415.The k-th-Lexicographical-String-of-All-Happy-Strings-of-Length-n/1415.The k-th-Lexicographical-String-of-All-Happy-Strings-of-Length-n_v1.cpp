class Solution {
    unordered_set<string>rets;
    string ans;
    int N,K;
public:
    string getHappyString(int n, int k) 
    {
        string s;
        ans = "";
        N = n;
        K = k;
        DFS(0,s);        
        return ans;
    }
    
    void DFS(int cur, string s)
    {
        if (cur==N)
        {
            rets.insert(s);
            if (rets.size()==K)
                ans = s;
            return;
        }
        
        if (ans!="") return;
        
        if (cur==0)
        {
            for (auto ch='a'; ch<='c'; ch++)
            {
                s.push_back(ch);
                DFS(cur+1, s);
                s.pop_back();
            }
        }
        else
        {
            for (auto ch='a'; ch<='c'; ch++)
            {
                if (ch==s.back()) continue;
                s.push_back(ch);
                DFS(cur+1, s);
                s.pop_back();
            }            
        }
    }
};
