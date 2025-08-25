class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>preMax(n);
        vector<int>sufMin(n);
        for (int i=0; i<n; i++)
            preMax[i] = max(i==0?0:preMax[i-1], nums[i]);

        for (int x: preMax) cout<<x<<" "; cout<<endl;

        for (int i=n-1; i>=0; i--)
            sufMin[i] = min((i==n-1)?INT_MAX:sufMin[i+1], nums[i]);

        vector<int>rets(n);
        rets[n-1] = preMax[n-1];
        for (int i=n-2; i>=0; i--) {
            if (preMax[i]>sufMin[i+1])
                rets[i] = rets[i+1];
            else
                rets[i] = preMax[i];
        }        

        return rets;
    }
};
