class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>next(numCourses);
        vector<int>InDegree(numCourses);
        for (auto p: prerequisites)
        {
            next[p[0]].push_back(p[1]);
            InDegree[p[1]]++;
        }
        queue<int>q;
        int count = 0;
        for (int i=0; i<numCourses; i++)
        {
            if (InDegree[i]==0) 
            {
                q.push(i);
                count++;
            }
        }
                    
        while (!q.empty())
        {
            int curCourse = q.front();
            q.pop();
            for (auto nextCourse: next[curCourse])
            {
                InDegree[nextCourse]--;
                if (InDegree[nextCourse]==0)
                {
                    q.push(nextCourse);
                    count++;
                }                    
            }
        }        
        
        return count==numCourses;        
    }
};
