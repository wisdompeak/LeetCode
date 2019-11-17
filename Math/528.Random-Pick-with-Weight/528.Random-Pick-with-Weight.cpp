class Solution {
    vector<int>p;
public:
    Solution(vector<int>& w) 
    {
        int sum = -1;
        for (auto ww: w)
        {
            sum+=ww;
            p.push_back(sum);
        }
    }
    
    int pickIndex() 
    {
        int r = rand()%(p.back()+1);
        auto iter = lower_bound(p.begin(),p.end(),r);
        return iter-p.begin();
    }
};
