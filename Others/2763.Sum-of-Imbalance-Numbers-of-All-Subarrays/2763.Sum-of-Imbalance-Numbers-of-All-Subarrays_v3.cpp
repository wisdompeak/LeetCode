class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<int>prevInvalid(n, -1);
        vector<int>val2pos(1005,-1);
        for (int i=0; i<n; i++)
        {
            prevInvalid[i] = val2pos[nums[i]+1];
            val2pos[nums[i]] = i;            
        }
                
        vector<int>afterInvalid(n+1, n);
        for (int i=0; i<1005; i++) val2pos[i] = n;
        for (int i=n-1; i>=0; i--)
        {
            afterInvalid[i] = min(val2pos[nums[i]], val2pos[nums[i]+1]);
            val2pos[nums[i]] = i;            
        }

        vector<int>prevLargerThanOne(n, -1);
        stack<int>st;
        for (int i=0; i<n; i++)
        {
            while (!st.empty() && nums[st.top()] <= nums[i]+1)
                st.pop();
            if (!st.empty()) prevLargerThanOne[i] = st.top();
            st.push(i);
        }
        
        vector<int>afterLargerThanOne(n, n);
        while (!st.empty()) st.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i]+1)
                st.pop();
            if (!st.empty()) afterLargerThanOne[i] = st.top();
            st.push(i);
        }        
        
        int ret = 0;
        for (int i=0; i<n; i++)
        {
            int a = i - prevInvalid[i];
            int b = afterInvalid[i] - i;
            int c = i - max(prevInvalid[i], prevLargerThanOne[i]);
            int d = min(afterInvalid[i], afterLargerThanOne[i]) - i;

            ret += a*b - c*d;
        }
        
        return ret;        
    }
};
