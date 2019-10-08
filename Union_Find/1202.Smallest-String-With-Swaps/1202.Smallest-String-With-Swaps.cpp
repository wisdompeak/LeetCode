class Solution {
    vector<int>Father;
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int N = s.size();
        Father.resize(N);
        for (int i=0; i<N; i++)
            Father[i] = i;
        
        for (auto& p :pairs)
        {
            int a = p[0];
            int b = p[1];
            if (FindFather(a)!=FindFather(b))
                Union(a,b);
        }
        
        unordered_map<int, vector<int>>Map; // root idx -> all indexes
        for (int i=0; i<N; i++)
        {
            Map[FindFather(i)].push_back(i);
        }
        
        for (auto x: Map)
        {
            string temp;
            for (auto idx : x.second)
                temp.push_back(s[idx]);
            sort(temp.begin(),temp.end());
            int k = 0;
            for (auto idx : x.second)
            {
                s[idx] = temp[k];
                k++;
            }
        }
        
        return s;
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
