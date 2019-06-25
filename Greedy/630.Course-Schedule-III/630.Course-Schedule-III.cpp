class Solution {
    static bool cmp(vector<int>a,vector<int>b)
    {
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(),courses.end(),cmp);        
        
        priority_queue<int>pq;        
        
        int day=0;
        
        for (int i=0; i<courses.size(); i++)
        {
            if (day+courses[i][0]<=courses[i][1])
            {
                day+=courses[i][0];
                pq.push(courses[i][0]);
            }
            else
            {
                if (!pq.empty() && pq.top()>courses[i][0])
                {
                    day=day-pq.top()+courses[i][0];
                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }
        
        return pq.size();
        
    }
};
