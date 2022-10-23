using LL = long long;
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        int n = nums.size();
        vector<pair<LL,LL>>arr;
        for (int i=0; i<n; i++)
        {
            arr.push_back({nums[i], cost[i]});
        }
        sort(arr.begin(), arr.end());
        
        vector<LL>left(n, 0);
        LL sum = arr[0].second;
        for (int i=1; i<n; i++)
        {
            LL delta = arr[i].first - arr[i-1].first;
            left[i] = left[i-1] + delta * sum;
            sum += arr[i].second;
        }
        
        vector<LL>right(n, 0);
        sum = arr[n-1].second;
        for (int i=n-2; i>=0; i--)
        {
            LL delta = arr[i+1].first - arr[i].first;
            right[i] = right[i+1] + delta * sum;
            sum += arr[i].second;
        }
        
        vector<LL>all(n,0);
        for (int i=0; i<n; i++)
            all[i] = (left[i] + right[i]);
        
        return *min_element(all.begin(), all.end());
        
    }
};
