using LL = long long;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) 
    {
        maxHeights.insert(maxHeights.begin(), 0);
        maxHeights.push_back(0);
        
        vector<LL>left = helper(maxHeights);
        
        reverse(maxHeights.begin(), maxHeights.end());        
        vector<LL>right = helper(maxHeights);
        reverse(right.begin(), right.end());
        
        reverse(maxHeights.begin(), maxHeights.end());
        
        LL ret = 0;
        
        for (int i=0; i<maxHeights.size(); i++)
        {
            ret = max(ret, left[i]+right[i]-maxHeights[i]);
        }
        
        return ret;
    }
    
    vector<LL>helper(vector<int>maxHeights)
    {
        int n = maxHeights.size();        
        stack<int>stk;
        vector<LL>arr(n);
        LL sum = 0;
        stk.push(0);
        arr[i] = 0;
        for (int i=1; i<n; i++)
        {   
            while (!stk.empty() && maxHeights[i] < maxHeights[stk.top()])
            {
                LL p1 = stk.top();
                stk.pop();
                LL p2 = stk.top();
                sum -= (LL)(p1-p2) * maxHeights[p1];
            }
            
            sum += (LL)(i- stk.top()) * maxHeights[i];
            arr[i] = sum;
            stk.push(i);
        }        
        return arr;        
    }
    
};
