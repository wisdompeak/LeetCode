class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) 
    {
        vector<int>rets;
        if (dfs(sums, n, rets))
            return rets;
        return {};
    }

    bool dfs(vector<int>sum, int n, vector<int>&rets)
    {
        if (n==1)
        {        
            if (sum[0]!=0 && sum[1]!=0)    
                return false;
            else
            {
                rets.push_back(sum[1]==0? sum[0]:sum[1]);            
                return true;    
            }            
        } 

        int k = sum.size();
        std::nth_element(sum.begin(), sum.begin()+k-1, sum.end());
        std::nth_element(sum.begin(), sum.begin()+k-2, sum.end());

        int x = sum[k-1]-sum[k-2];
        multiset<int>Set1(sum.begin(), sum.end());
        vector<int>sum1;
        for (int i=0; i<k/2; i++)
        {
            int num = *Set1.rbegin();
            if (Set1.find(num-x)==Set1.end())
                break;
            Set1.erase(Set1.lower_bound(num));    
            Set1.erase(Set1.lower_bound(num-x));
            sum1.push_back(num-x);
        }
        if (sum1.size()==k/2)
        {
            rets.push_back(x);
            if (dfs(sum1, n-1, rets))
                return true;
            rets.pop_back();
        }

        x = -x;
        multiset<int>Set2(sum.begin(), sum.end());
        vector<int>sum2;
        for (int i=0; i<k/2; i++)
        {
            int num = *Set2.begin();
            if (Set2.find(num-x)==Set2.end())
                break;
            Set2.erase(Set2.lower_bound(num-x));
            Set2.erase(Set2.lower_bound(num));
            sum2.push_back(num-x);
        }
        if (sum2.size()==k/2)
        {
            rets.push_back(x);
            if (dfs(sum2, n-1, rets))
                return true;
            rets.pop_back();
        }

        return false;
    }
};
