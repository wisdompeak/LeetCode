class Solution {
public:
    int Father[2*100005];
    
    
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x>y) Father[y] = x;
        else Father[x] = y;
    }  
    
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
    
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        int MX = *max_element(nums.begin(), nums.end());
        vector<int>primes = Eratosthenes(MX);
        int M = primes.size();
        
        int N = nums.size();
        unordered_map<int,int>idx;
        for (int j=0; j<primes.size(); j++)
            idx[primes[j]] = j;
      
        for (int i=0; i<N+M; i++)
            Father[i] = i;
        
        for (int i=0; i<N; i++)
        {            
            int x = nums[i];
            for (int j=0; j<M; j++)
            {
                int p = primes[j];
                if (p > x) break;
                if (p*p > x)
                {
                    if (FindFather(i)!=FindFather(N+idx[x]))
                        Union(i, N+idx[x]);
                    break;
                }
                
                if (x%p==0)
                {
                    if (FindFather(i)!=FindFather(N+j))
                        Union(i, N+j);
                    while (x%p==0)
                        x /= p;
                }
            }
        }
        
        for (int i=0; i<N; i++)
        {
            if (FindFather(i)!=FindFather(0))
                return false;
        }
        
        return true;
    }
};
