class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        vector<int>q({0});
        int count = 0;
        for (auto x:hours)
        {
            if (x>8)
                count++;
            else
                count--;
            q.push_back(count);
        }
        
        map<int,int>Map;
        Map[0] = 0;
        int result = 0;
        for (int i=1; i<q.size(); i++)
        {
            int k = INT_MAX;
            for (auto x:Map)
            {
                if (x.first >= q[i])
                    break;
                k = min(k, x.second);
            }
            result = max(result, i-k);
            if (Map.begin()->first > q[i])
            {
                Map[q[i]] = i;
            }                
        }
        return result;
    }
