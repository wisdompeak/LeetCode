class Solution {
    vector<int>children[100005];
    int setIdx[100005];
    vector<int>rets;   
    vector<unordered_set<int>>setList; 
    vector<int>nums;
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) 
    {
        this->nums = nums;
        int n = parents.size();
        for (int i=1; i<n; i++)        
            children[parents[i]].push_back(i);

        rets.resize(n);
        dfs(0);
        return rets;
    }

    void dfs(int node)
    {
        if (children[node].empty())
        {
            setIdx[node] = setList.size();
            setList.push_back({nums[node]});
            rets[node] = nums[node]==1?2:1;     

            cout<<node<<":"<<setIdx[node]<<" "<<setList[setIdx[node]].size()<<endl;       
        }
        else
        {   
            for (int child: children[node])
                dfs(child);

            int maxSetSize = 0;
            int maxSetIdx;
            for (int child: children[node])
            {
                if (setList[setIdx[child]].size() > maxSetSize)
                {
                    maxSetSize = setList[setIdx[child]].size();
                    maxSetIdx = setIdx[child];
                }
            }

            for (int child: children[node])
            {
                if (setIdx[child] == maxSetIdx) continue;
                for (int x: setList[setIdx[child]])
                    setList[maxSetIdx].insert(x);
            }
            setList[maxSetIdx].insert(nums[node]);
            setIdx[node] = maxSetIdx;

            int maxMissing = 0;            
            for (int child: children[node])            
                maxMissing = max(maxMissing, rets[child]);
            int x = maxMissing;
            while (setList[maxSetIdx].find(x)!=setList[maxSetIdx].end())
                x++;
            rets[node] = x;
        }

    }
};
