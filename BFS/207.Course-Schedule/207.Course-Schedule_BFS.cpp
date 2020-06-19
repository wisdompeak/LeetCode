class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        unordered_map<int,vector<int>>next;
        unordered_map<int,int>InDegree;
        for (auto p: prerequisites)
        {
            next[p.first].push_back(p.second);
            InDegree[p.second]++;
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
