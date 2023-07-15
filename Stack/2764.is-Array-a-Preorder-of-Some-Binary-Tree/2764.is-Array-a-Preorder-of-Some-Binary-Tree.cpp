class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) 
    {
        stack<int>stk;
        for (auto& node: nodes)
        {
            if (stk.empty() || node[1] == stk.top())
                stk.push(node[0]);
            else
            {
                while (!stk.empty() && node[1] != stk.top())
                    stk.pop();
                if (stk.empty()) return false;
                stk.push(node[0]);
            }
        }

        return true;
    }
};
