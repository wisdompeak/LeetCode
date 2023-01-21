using LL = long long;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        vector<pair<LL,LL>>arr;
        for (int i=0; i<n; i++)
            arr.push_back({nums2[i], nums1[i]});
        
        sort(arr.rbegin(), arr.rend());
        
        priority_queue<LL, vector<LL>, greater<>>pq;
        LL minVal = INT_MAX;
        LL sum = 0;
        LL ret = 0;
        for (int i=0; i<n; i++)
        {
            minVal = arr[i].first;
            sum += arr[i].second;
            pq.push(arr[i].second);
            if (pq.size()>k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size()==k)
                ret = max(ret, sum * minVal);
        }
        return ret;
        
    }
};
