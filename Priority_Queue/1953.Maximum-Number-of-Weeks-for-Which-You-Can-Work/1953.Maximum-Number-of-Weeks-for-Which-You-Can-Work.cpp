using LL = long long;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) 
    {                
        LL sum = accumulate(milestones.begin(), milestones.end(), 0LL);        
        LL mx = *max_element(milestones.begin(), milestones.end());
        if (mx <= sum/2) return sum;
        else return (sum-mx)*2+1;
    }
};
