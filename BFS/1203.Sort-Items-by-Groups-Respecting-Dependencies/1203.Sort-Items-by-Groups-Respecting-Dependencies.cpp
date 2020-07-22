class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) 
    {
        unordered_map<int, unordered_set<int>>groupItems;
        int nextGroupId = m;

        for (int i=0; i<n; i++)
        {
            if (group[i]==-1)
            {
                group[i] = nextGroupId;
                nextGroupId += 1;
            }
            groupItems[group[i]].insert(i);
        }

        // build graph inside each group
        unordered_map<int, unordered_set<int>>next;
        unordered_map<int, int>inDegree;
        for (int i=0; i<n; i++)        
            for (int j: beforeItems[i])
            {
                if (group[i]!=group[j]) continue;
                if (next[j].find(i)==next[j].end())                
                {
                    next[j].insert(i);
                    inDegree[i] += 1;
                }
            }
        // sort nodes inside each group
        unordered_map<int, vector<int>>groupItemsOrdered;
        for (auto x: groupItems)
        {
            int groupId = x.first;
            groupItemsOrdered[groupId] = topologySort(groupItems[groupId], next, inDegree);
            if (groupItemsOrdered[groupId].size() != groupItems[groupId].size())
                return {};
        }

        // build graph among groups
        next.clear();
        inDegree.clear();
        for (int i=0; i<n; i++)        
            for (int j: beforeItems[i])
            {
                if (group[i]==group[j]) continue;
                if (next[group[j]].find(group[i])==next[group[j]].end())                
                {
                    next[group[j]].insert(group[i]);
                    inDegree[group[i]] += 1;
                }
            }
        // sort groups
        unordered_set<int>groups;
        for (int i=0; i<n; i++) groups.insert(group[i]);
        vector<int>groupOrdered = topologySort(groups, next, inDegree);

        vector<int>rets;
        for (int groupId: groupOrdered)
        {
            for (auto node: groupItemsOrdered[groupId])
                rets.push_back(node);
        }
        return rets;
    }

    vector<int> topologySort (unordered_set<int>&nodes, unordered_map<int, unordered_set<int>>&next, unordered_map<int, int>&inDegree)
    {
        queue<int>q;
        vector<int>ret;
        for (auto node: nodes)
        {
            if (inDegree[node]==0)
                q.push(node);
        }
         while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            ret.push_back(cur);            
            for (auto next: next[cur] )
            {
                inDegree[next] -= 1;
                if (inDegree[next] == 0)
                    q.push(next);
            }
        }
        
        if (ret.size()==nodes.size())
            return ret;
        else
            return {};
    }
};
