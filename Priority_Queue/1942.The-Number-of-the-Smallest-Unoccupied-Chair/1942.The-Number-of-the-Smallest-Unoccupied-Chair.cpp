using PII = pair<int,int>;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        priority_queue<int, vector<int>, greater<>>empty;
        for (int i=0; i<times.size(); i++)
            empty.push(i);
        
        for (int i=0; i<times.size(); i++)
            times[i].push_back(i);
        sort(times.begin(), times.end());
        
        priority_queue<PII, vector<PII>, greater<>> used;
        
        for (auto time: times)
        {
            int start = time[0];
            int end = time[1];
            int people = time[2];
            
            while (!used.empty() && used.top().first <= start)
            {
                empty.push(used.top().second);
                used.pop();
            }
            
            int chair = empty.top();
            empty.pop();
            if (people==targetFriend) return chair;
            
            used.push({end, chair});
        }
        
        return -1;
    }
};
