class Solution {
    int Father[20000];
    int states[20000];
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
        if (x<y) Father[y] = x;
        else Father[x] = y;
    }     
public:
    vector<int> groupStrings(vector<string>& words) 
    {
        int n = words.size();        
        for (int i=0; i<n; i++)
            Father[i] = i;
                
        unordered_map<int, int>Map;    // num -> idx    
        for (int i=0; i<n; i++)
        {
            string& word = words[i];
            int state = 0;
            for (int i=0; i<word.size(); i++)
            {
                int k = word[i]-'a';
                state |= (1<<k);
            }
            states[i] = state;
            if (Map.find(state)==Map.end())
                Map[state] = i;        
            else
            {
                int k = Map[state];
                if (FindFather(i)!=FindFather(k))
                    Union(i,k);
            }         
        }
         
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<26; j++)
            {
                if (((states[i]>>j)&1)==0) continue;
                int newState = states[i] - (1<<j);
                if (Map.find(newState)==Map.end())
                    Map[newState] = i;
                else
                {
                    int k = Map[newState];
                    if (FindFather(i)!=FindFather(k))
                        Union(i,k);
                }
            }
        }        
        
        unordered_map<int, int>group;
        for (int i=0; i<n; i++)
            group[FindFather(i)]+=1;
        
        int maxGroup = 0;
        for (auto x: group)
            maxGroup = max(maxGroup, x.second);
        
        return {(int)group.size(), maxGroup};
        
    }
};
