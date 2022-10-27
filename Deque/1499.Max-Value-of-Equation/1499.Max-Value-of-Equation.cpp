class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        int ret = INT_MIN;
        deque<int>q;
        for (int i=0; i<points.size(); i++)
        {
            while (q.size()>0 && points[q.front()][0] < points[i][0]-k) {
                q.pop_front();
            }
            
            if (q.size() > 0) {
        	    ret = max(ret, -points[q.front()][0]+points[q.front()][1] + points[i][0]+points[i][1]);
            }
            
            while (q.size()>0 && -points[q.back()][0]+points[q.back()][1] < -points[i][0]+points[i][1]) {
                q.pop_back();
            }
            
            q.push_back(i);
            

        }
        return ret;
    }
};
