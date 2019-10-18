class Solution {
    vector<int>Father;
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int N = row.size();
        Father.resize(N);
        
        for (int i=0; i<N; i+=2)
        {
            Father[i] = i;
            Father[i+1] = i;
        }
        
        for (int i=0; i<N; i+=2)
        {
            int a = row[i];
            int b = row[i+1];
            if (FindFather(a)!=FindFather(b))
                Union(a,b);
        }
        
        unordered_map<int,int>count;
        for (int i=0; i<N; i++)
            count[FindFather(i)] += 1;
        
        int ret = 0;
        for (auto x: count)
           ret += x.second/2-1;
        
        return ret;
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

