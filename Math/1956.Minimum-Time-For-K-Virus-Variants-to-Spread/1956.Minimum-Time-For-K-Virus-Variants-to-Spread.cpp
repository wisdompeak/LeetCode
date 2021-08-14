class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[0]+a[1] < b[0]+b[1];
    }
public:
    int minDayskVariants(vector<vector<int>>& points, int k) {
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        
        long ret = INT_MAX;
        
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
            {
                vector<pair<long,int>>diffs;
                for (int t=i; t<=j; t++)
                {
                    diffs.push_back({points[t][0]-points[t][1], t});
                }
                sort(diffs.begin(), diffs.end());
                
                vector<int> pivots;
                for (int t=0; t<diffs.size(); t++)
                {
                    if (diffs[t].second==i || diffs[t].second==j)
                        pivots.push_back(t);
                }
                int pLeft = pivots[0], pRight = pivots[1];
                                
                int r = 0;
                long minDiff = INT_MAX;
                for (int l=0; l<diffs.size(); l++)
                {
                    if (l > pLeft) break;
                    while (r<diffs.size() && (r < pRight || r-l+1 < k))
                        r++;
                    
                    if (r<diffs.size())                        
                        minDiff = min(minDiff, diffs[r].first - diffs[l].first);
                }
                
                long candidate1 = points[j][0]+points[j][1] - (points[i][0]+points[i][1]);
                long candidate2 = minDiff;
                ret = min(ret, max(candidate1, candidate2));
            }
        
        return (ret+1)/2;    
    }
};
