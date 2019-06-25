class Solution {
public:
    vector<string> braceExpansionII(string expression) 
    {
        string S = expression;
                
        auto resultSet =  dfs(S,0,S.size()-1);
        
        vector<string>results;
        for (auto x:resultSet)
            results.push_back(x);
        sort(results.begin(),results.end());
        return results;        
    }
    
    unordered_set<string>dfs(string&S, int a, int b)
    {
        stack<unordered_set<string>>Stack;
        unordered_set<string>cur={};       
                       
        for (int i=a; i<=b; i++)            
        {            
            if (S[i]=='{')
            {
                int level = 1;
                int j = i+1;
                while (j<=b && level>0)
                {
                    level += (S[j]=='{');
                    level -= (S[j]=='}');
                    if (level==0)
                        break;
                    else
                        j++;
                }
                auto next = dfs(S,i+1,j-1);                
                cur = product(cur,next);
                i = j;                
            }
            else if (S[i]==',')
            {
                Stack.push(cur);
                cur = {};
            }
            else
            {                                
                int j = i+1;
                while (j<=b && isalpha(S[j]))
                    j++;
                unordered_set<string>next({S.substr(i,j-i)});
                cur = product(cur, next);                
                i = j-1;
            }
        }
        
        while (!Stack.empty())
        {
            for (auto x: Stack.top())
                cur.insert(x);
            Stack.pop();
        }
        return cur;
    }
    
    unordered_set<string>product(unordered_set<string>&A, unordered_set<string>&B)
    {
        if (A.size()==0)
            A.insert("");
        unordered_set<string>results;
        for (auto x:A)
            for (auto y:B)
                results.insert(x+y);
        return results;
    }    
};
