using LL = long long;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, vector<LL>>Map;
        for (int i=0; i<nums.size(); i++)
            Map[nums[i]].push_back(i);
        
        unordered_map<int,LL>ans;
        unordered_map<int,LL>idx;
        for (auto& [k,v]: Map)
        {
            idx[k] = 0;
            LL sum = 0;
            for (int p: v)
                sum += abs(p - v[0]);
            ans[k] = sum;            
        }
        
                
        vector<LL>rets;
        for (int x: nums)
        {
            rets.push_back(ans[x]);
            int i = idx[x];
            if (i==Map[x].size()-1) continue;
            LL temp = ans[x];
            int m = Map[x].size();
            temp += (Map[x][i+1]-Map[x][i])*(i+1);
            temp -= (Map[x][i+1]-Map[x][i])*(m-1-i);
            ans[x] = temp;
            idx[x] = i+1;
        }
        
        return rets;
        
    }
};
