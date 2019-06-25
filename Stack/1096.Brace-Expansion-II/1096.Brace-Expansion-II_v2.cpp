class Solution {
public:
    vector<string> braceExpansionII(string S) 
    {
        string expression;
        for (int i=0; i<S.size(); i++)
        {
            if (isalpha(S[i]))
            {
                expression.push_back('{');
                expression.push_back(S[i]);
                expression.push_back('}');
            }
            else
                expression.push_back(S[i]);                
        }
        
        stack<unordered_set<string>>Stack;
        stack<int>StackFlag;
        
        unordered_set<string>cur={};
        
        for (int i=0; i<expression.size(); i++)
        {
            if (expression[i]=='{')
            {
                Stack.push(cur);
                cur = {};
                StackFlag.push(2);
            }
            else if (expression[i]==',')
            {
                Stack.push(cur);
                cur = {};
                StackFlag.push(1);
            }
            else if (expression[i]=='}')
            {
                // sum up all the elements in the same level                
                while (!StackFlag.empty() && StackFlag.top()==1)
                {                                        
                    for (auto x:Stack.top())
                        cur.insert(x);                    
                    Stack.pop();
                    StackFlag.pop();                    
                }
                // multiply with the last element in the upper level
                if (!StackFlag.empty() && StackFlag.top()==2)
                {
                    unordered_set<string>temp;
                    if (Stack.top().size()==0)
                        Stack.top().insert("");
                    for (auto x: Stack.top())
                        for (auto y:cur)
                            temp.insert(x+y);
                    cur = temp;
                    Stack.pop();
                    StackFlag.pop();
                }
                              
            }
            else
            {
                int j=i+1;
                while (j<expression.size() && isalpha(expression[j]))
                    j++;
                cur={expression.substr(i,j-i)};
                i = j-1;                
            }
        }               
        
        vector<string>results;
        for (auto x:cur)
            results.push_back(x);
        sort(results.begin(),results.end());
        
        return results;
    }
};
