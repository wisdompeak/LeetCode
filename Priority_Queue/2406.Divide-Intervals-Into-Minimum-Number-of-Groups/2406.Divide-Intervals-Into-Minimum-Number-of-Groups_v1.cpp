class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        priority_queue<int, vector<int>, greater<>>pq;
        
        sort(intervals.begin(), intervals.end());
                
        int ret = 0;
        
        for (int i=0; i<intervals.size(); i++)
        {
            if (pq.empty() || pq.top() >= intervals[i][0])
            {
                pq.push(intervals[i][1]);
            }
            else
            {
                pq.pop();                
                pq.push(intervals[i][1]);
            }
            
            ret = max(ret, (int)pq.size());                        
        }
        
        return ret;
    }
};
