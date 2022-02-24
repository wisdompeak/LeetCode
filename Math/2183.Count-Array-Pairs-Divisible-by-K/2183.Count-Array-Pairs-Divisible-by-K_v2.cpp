class Solution {
public:
    long long countPairs(vector<int>& nums, int k) 
    {
        unordered_set<int>yueshu;
        for (int i=1; i*i<=k; i++)
        {
            if (k%i!=0) continue;
            yueshu.insert(i);
            yueshu.insert(k/i);
        }
        
        long long ret = 0;
        unordered_map<int,int>count;
        for (int i=nums.size()-1; i>=0; i--)
        {
            int a = gcd(nums[i],k);
            int b = k/a;
            if (count.find(b)!=count.end())
                ret += count[b];
            
            for (int x: yueshu)
            {
                if (nums[i]%x==0)
                    count[x]++;                
            }
        }
                
        return ret;        
    }
};
