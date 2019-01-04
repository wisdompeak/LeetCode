class Solution {
public:
    int numFriendRequests(vector<int>& ages) 
    {
        sort(ages.begin(),ages.end());
        
        vector<int>Map(121,0);
        vector<int>sums(121,0);
        
        for (auto age:ages)
            Map[age]++;
        
        for (int i=1; i<=120; i++)
            sums[i] = sums[i-1]+Map[i];
        
        int count = 0;
        for (int i=0; i<ages.size(); i++)
        {
            int lower = 0.5*ages[i]+7;
            int upper = ages[i];
            if (lower>=upper) continue;
            count += sums[upper]-sums[lower]-1;
        }
        return count;
    }
};
