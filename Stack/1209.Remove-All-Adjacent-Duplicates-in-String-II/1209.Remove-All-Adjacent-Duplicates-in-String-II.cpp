class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char, int>>Stack;

        for (auto ch: s)
        {
            if (Stack.empty() || Stack.top().first!=ch)            
                Stack.push({ch, 1});            
            else            
                Stack.push({ch, Stack.top().second+1});            

            if (Stack.top().second==k)
            {
                for (int i=0; i<k; i++)
                    Stack.pop();
            }
        }

        string ret;
        while (!Stack.empty())
        {
            ret.push_back(Stack.top().first);
            Stack.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;

    }
};
