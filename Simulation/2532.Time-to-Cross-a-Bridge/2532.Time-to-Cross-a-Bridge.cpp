using PII = pair<int,int>;
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) 
    {        
        priority_queue<PII, vector<PII>, greater<>>leftArrive;
        priority_queue<PII, vector<PII>, greater<>>rightArrive;
        for (int i=0; i<k; i++)        
            leftArrive.push({0, i});        

        int nextFree = 0;
        priority_queue<PII>leftWait;
        priority_queue<PII>rightWait;
        
        int ret = 0;
        int crossed = 0;
        int returned = 0;

        while (returned < n)
        {
            if (crossed == n)
            {
                while (!leftWait.empty()) 
                    leftWait.pop();
                while (!leftArrive.empty())
                    leftArrive.pop();
            }

            while (!leftArrive.empty() && leftArrive.top().first <= nextFree)
            {
                auto [arriveTime, id] = leftArrive.top();
                leftArrive.pop();                
                leftWait.push({time[id][0]+time[id][2], id});
            }
            while (!rightArrive.empty() && rightArrive.top().first <= nextFree)
            {
                auto [arriveTime, id] = rightArrive.top();
                rightArrive.pop();
                rightWait.push({time[id][0]+time[id][2], id});
            }            

            if (leftWait.empty() && rightWait.empty())
            {
                int t1 = leftArrive.empty() ? INT_MAX : leftArrive.top().first;
                int t2 = rightArrive.empty() ? INT_MAX : rightArrive.top().first;
                nextFree = min(t1, t2);
                continue;
            }

            if (!rightWait.empty())   // R -> L
            {
                auto [_, id] = rightWait.top();
                rightWait.pop();
                nextFree += time[id][2];
                leftArrive.push({nextFree+time[id][3], id});
                returned++;
                ret = max(ret, nextFree);
            }
            else if (!leftWait.empty() && crossed < n)   // L -> R
            {
                auto [_, id] = leftWait.top();
                leftWait.pop();
                nextFree += time[id][0];
                rightArrive.push({nextFree+time[id][1], id});
                crossed++;
            }
        }
        
        return nextFree;
    }
};
