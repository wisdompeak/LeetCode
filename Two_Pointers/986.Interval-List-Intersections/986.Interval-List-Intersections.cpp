class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        int m = firstList.size();
        int n = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>>rets;
        while (i<m && j<n)
        {
            if (firstList[i][1]<secondList[j][0])
                i++;
            else if (firstList[i][0]>secondList[j][1])
                j++;
            else
            {
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]); 
                rets.push_back({start, end});
                if (firstList[i][1]<secondList[j][1])
                    i++;
                else
                    j++;
            }
        }
        return rets;

    }
};
