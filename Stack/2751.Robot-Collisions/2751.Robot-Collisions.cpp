class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        int n = positions.size();
        vector<vector<int>>robots;
        for (int i=0; i<n; i++)
        {
            int dir = (directions[i]=='L')?-1:1;
            robots.push_back({positions[i], healths[i], dir, i});
        }
        sort(robots.begin(), robots.end());
        
        vector<vector<int>>Stack;
        for (int i=0; i<n; i++)
        {
            if (robots[i][2]==1)
                Stack.push_back(robots[i]);
            else
            {
                while (!Stack.empty() && Stack.back()[2]==1)
                {
                    auto r = Stack.back();
                    Stack.pop_back();
                    if (r[1] < robots[i][1])
                    {
                        robots[i][1] -= 1;
                    }
                    else if (r[1] == robots[i][1])
                    {
                        robots[i][1] -= r[1];
                        break;
                    }
                    else
                    {
                        r[1] -= 1;
                        robots[i][1] = 0;
                        Stack.push_back(r);
                        break;
                    }
                }
                if (robots[i][1] > 0)
                    Stack.push_back(robots[i]);         
            }            
        }
        
        sort(Stack.begin(), Stack.end(), [](vector<int>&a, vector<int>&b){return a[3]<b[3];});
        
        vector<int>rets;
        for (int i=0; i<Stack.size(); i++)
            rets.push_back(Stack[i][1]);
        return rets;
    }
};
