class Solution {
    vector<int>Father;
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        Father.resize(n);
        vector<int>edges(n,0);
        unordered_map<int,int>cables;
        unordered_map<int,int>elements;

        for (int i=0; i<n; i++)
            Father[i] = i;

        for (auto& edge: connections)
        {
            if (FindFather(edge[0])!=FindFather(edge[1]))
                Union(edge[0],edge[1]);
            edges[edge[0]]+=1;
            edges[edge[1]]+=1;
        }

        for (int i=0; i<n; i++)
        {
            Father[i] = FindFather(i);
            cables[Father[i]] += edges[i];
            elements[Father[i]] += 1;
        }

        int redundant = 0;
        int islands = cables.size();
        for (auto x: cables)
        {
            int root = x.first;
            redundant += cables[root]/2+1-elements[root];
        }

        if (redundant>=islands-1)
            return islands-1;
        else 
            return -1;        
    }

    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y)
            Father[y] = x;
        else
            Father[x] = y;
    }
};
