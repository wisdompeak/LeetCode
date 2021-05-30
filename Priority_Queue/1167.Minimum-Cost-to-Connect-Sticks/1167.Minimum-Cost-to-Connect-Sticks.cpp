class Solution {
public:
    int connectSticks(vector<int>& sticks) 
    {
        multiset<int>Set;
        int sum = 0;
        for (auto x: sticks)
        {
            Set.insert(x);
        }
        for (int i=0; i<sticks.size()-1; i++)
        {
            int x = *(Set.begin());
            Set.erase(Set.begin());
            int y = *(Set.begin());
            Set.erase(Set.begin());
            sum += x+y;
            Set.insert(x+y);
        }
        return sum;
    }
};
