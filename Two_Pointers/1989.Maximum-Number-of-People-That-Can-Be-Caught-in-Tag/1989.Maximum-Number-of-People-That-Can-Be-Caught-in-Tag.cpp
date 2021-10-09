class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) 
    {
        int n = team.size();        
        int j = 0;
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            if (team[i]!=0) continue;
            j = max(j, i-dist);
            while (j<n && team[j]!=1)
                j++;
            if (j<n && abs(j-i)<=dist)
            {
                ret++;
                j++;
            }
        }
        return ret;        
    }
};
