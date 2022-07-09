class Solution {
public:
    int convertArray(vector<int>& nums) {
        int ret = solve(nums);
        reverse(nums.begin(),nums.end());
        ret = min(ret, solve(nums));
        return ret;
    }
    
    int solve(vector<int>& nums) {
        int res = 0;
        priority_queue<int> que;
        for(auto num: nums) {
            if(!que.empty() && que.top()>num) {
                res += que.top() - num;
                que.pop();
                que.push(num);
            }
            que.push(num);
        }
        return res;
    }    
};
