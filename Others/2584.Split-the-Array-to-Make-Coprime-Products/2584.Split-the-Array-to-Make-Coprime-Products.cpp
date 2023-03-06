class Solution {
public:
    vector<int>Eratosthenes(int n)
    {
        vector<int>q(n+1,0);
        vector<int>primes;
        for (int i=2; i<=sqrt(n); i++)
        {
            if (q[i]==1) continue;
            int j=i*2;
            while (j<=n)
            {
                q[j]=1;
                j+=i;
            }
        }        
        for (int i=2; i<=n; i++)
        {
            if (q[i]==0)
                primes.push_back(i);                
        }
        return primes;
    }
    
    int findValidSplit(vector<int>& nums) 
    {
        int K = *max_element(nums.begin(), nums.end());
        vector<int>primes = Eratosthenes(K);
        
        unordered_map<int,pair<int,int>>Map;                
        for (int i=0; i<nums.size(); i++)
        {
            int x = nums[i];
            for (int p: primes)
            {
                if (p*p>x) 
                {
                    if (Map.find(x)==Map.end())
                        Map[x].first = i;
                    Map[x].second = i;
                    break;
                }                
                
                if (x%p==0)
                {
                    if (Map.find(p)==Map.end())
                        Map[p].first = i;
                    Map[p].second = i;
                }
                while (x%p==0)
                {
                    x/=p;
                }
            }
        }
        
        int n = nums.size();
        vector<int>diff(n+1);        
        for (auto& [k, v]: Map)
        {
            if (v.first == v.second) continue;
            diff[v.first]+=1;
            diff[v.second]-=1;
        }
        
        int sum = 0;
        for (int i=0; i<n-1; i++)
        {
            sum += diff[i];
            if (sum == 0)
                return i;
        }
        return -1;
                
    }
};
