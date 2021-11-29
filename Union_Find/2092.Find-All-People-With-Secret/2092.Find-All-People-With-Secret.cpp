class Solution {
    vector<int>Father;
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
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[2]<b[2];
    }
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        Father.resize(n);
        for (int i=0; i<n; i++)
            Father[i] = i;
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        unordered_set<int>Set;
        Set.insert(0);
        Set.insert(firstPerson);
        Father[firstPerson] = 0;
        for (int i=0; i<meetings.size(); i++)
        {            
            unordered_set<int>temp;

            int j;            
            for (j=i; j<meetings.size() && meetings[j][2]==meetings[i][2]; j++)
            {
                int a = meetings[j][0], b = meetings[j][1], t = meetings[j][2];
                temp.insert(a);
                temp.insert(b);
                if (FindFather(a)!=FindFather(b))
                    Union(a,b);
            }
                        
            for (auto x: temp)
            {
                if (FindFather(x)!=0) Father[x] = x;
                else Set.insert(x); 
            }

            i = j-1;
        }
        
        vector<int>rets(Set.begin(), Set.end());
        return rets;
        
    }
};
