ass Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        if (s.size()==0) return "";

        stack<char>Stack;
        unordered_map<char,int>Map;
        unordered_map<char,int>Visited;

        for (int i=0; i<s.size(); i++)
        {
            Map[s[i]]++;
            Visited[s[i]]=0;
        }

        for (int i=0; i<s.size(); i++)
        {
            if (Visited[s[i]]==1)
            {
                Map[s[i]]--;
            }

            else if (Stack.empty() || Visited[s[i]]==0 && s[i]>=Stack.top())
            {
                Stack.push(s[i]);
                Map[s[i]]--;
                Visited[s[i]]=1;
            }

            else if (Visited[s[i]]==0 && s[i]<Stack.top())
            {
                while (!Stack.empty() && Stack.top()>s[i] && Map[Stack.top()]>0)
                {
                    Visited[Stack.top()]=0;
                    Stack.pop();
                }
                Stack.push(s[i]);
                Map[s[i]]--;
                Visited[s[i]]=1;
            }
        }

        string result;
        while (!Stack.empty())
        {
            result.push_back(Stack.top());
            Stack.pop();
        }
        reverse(result.begin(),result.end());      
        
        return result;
    }
};
