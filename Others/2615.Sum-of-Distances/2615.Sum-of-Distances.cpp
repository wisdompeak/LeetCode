using LL = long long;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, vector<LL>>Map;
        for (int i=0; i<nums.size(); i++)
            Map[nums[i]].push_back(i);
        
        vector<LL>rets(n);        
        for (auto& [_, arr]: Map)
        {
            int m = arr.size();
            LL sum = 0;            
            for (int x: arr)
                sum += abs(x - arr[0]);
            rets[arr[0]] = sum;

            for (int i=0; i+1<m; i++)
            {                
                int d = arr[i+1]-arr[i];
                sum += (i+1)*d;
                sum -= (m-(i+1))*d;
                rets[arr[i+1]] = sum;
            }                        
        }

        return rets;
  }
};
