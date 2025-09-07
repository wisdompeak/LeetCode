class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>nextGreater(n, -1);
        vector<int>prevGreater(n, -1);
        vector<int>st;
        for (int i=0; i<n; i++) {
            while (!st.empty() &&  nums[st.back()]<nums[i]) st.pop_back();
            if (!st.empty()) prevGreater[i] = st.back();
            st.push_back(i);
        }
        st.clear();

        for (int i=n-1; i>=0; i--) {
            while (!st.empty() &&  nums[st.back()]<nums[i]) st.pop_back();
            if (!st.empty()) nextGreater[i] = st.back();
            st.push_back(i);
        }

        long long ret = 0;
        for (int i=0; i<n; i++) {
            if (prevGreater[i]!=-1 && i-prevGreater[i]>=2) ret++;
            if (nextGreater[i]!=-1 && nextGreater[i]-i>=2) ret++;
        }
        return ret;
    }
};
