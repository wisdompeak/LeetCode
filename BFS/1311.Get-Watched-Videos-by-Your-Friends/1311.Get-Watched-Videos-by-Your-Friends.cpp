class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        int n = watchedVideos.size();
        vector<int>visited(n,0);

        queue<int>q;        
        q.push(id);
        visited[id] = 1;

        int step = 0;
        vector<int>persons;
        while (!q.empty())
        {
            int len = q.size();
            step += 1;
            while (len--)
            {
                int cur = q.front();
                q.pop();

                for (auto f: friends[cur])
                {
                    if (visited[f]==1) continue;
                    visited[f] = 1;
                    q.push(f);
                    if (step==level)
                        persons.push_back(f);
                }
            }
            if (step==level) break;
        }

        unordered_set<string>VideoSet;
        for (auto p: persons)
            for (auto v: watchedVideos[p])
                VideoSet.insert(v);

        unordered_map<string,int>freq;
        for (auto p: persons)
            for (auto v: watchedVideos[p])
                freq[v] += 1;
        
        vector<pair<int,string>>temp;
        for (auto v: VideoSet)
            temp.push_back({freq[v], v});
        sort(temp.begin(), temp.end());

        vector<string>rets;
        for (auto x: temp)
            rets.push_back(x.second);
        return rets;
    }
};
