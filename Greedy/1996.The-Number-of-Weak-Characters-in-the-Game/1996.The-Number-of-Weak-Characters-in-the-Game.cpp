class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]>b[1];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        sort(properties.begin(), properties.end(), cmp);
        stack<int>Stack;
        int ret = 0;
        for (int i=0; i<properties.size(); i++)
        {
            while (!Stack.empty() && Stack.top() < properties[i][1])
            {
                Stack.pop();
                ret++;
            }
            Stack.push(properties[i][1]);
        }
        return ret;
    }
};
