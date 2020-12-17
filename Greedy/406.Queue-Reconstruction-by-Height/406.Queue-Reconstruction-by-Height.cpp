class Solution {
public:
    static bool cmp(pair<int,int>a,  pair<int,int>b)
    {
        if (a.first==b.first)
            return a.second<b.second;
        else
            return a.first>b.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) 
    {
        sort(people.begin(),people.end(),cmp);
        vector<pair<int, int>>results;
        for (int i=0; i<people.size(); i++)
        {
            if (results.size()==0)
            {
                results.push_back(people[i]);
                continue;
            }
            
            int pos = people[i].second;
            results.insert(results.begin()+pos,people[i]);
        }
        return results;
    }
};
