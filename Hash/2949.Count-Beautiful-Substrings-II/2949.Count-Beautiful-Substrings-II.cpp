class Solution {
    unordered_set<char>Set = {'a','e','i','o','u' };
    
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

    long long beautifulSubstrings(string s, int k) 
    {
        vector<int>primes = Eratosthenes(k);
        int m = 1;
        for (int p:primes)
        {
            int count = 0;
            while (k%p==0)
            {
                count++;
                k/=p;
            }
            if (count!=0 && count%2==1)
                m *= pow(p, (count+1)/2);
            else if (count!=0 && count%2==0)
                m *= pow(p, count/2);
        }
        m*=2;

        int n = s.size();
        s.insert(s.begin(), '#');
        int ret = 0;
        
        map<int, unordered_map<int,int>>Map;
        Map[0][0]=1;
        
        int count = 0;
        
        for (int i=1; i<=n; i++)
        {
            if (Set.find(s[i])!=Set.end())
                count++;
            else
                count--;

            if (Map.find(count)!=Map.end() && Map[count].find(i%m)!=Map[count].end())
                ret += Map[count][i%m];
            
            Map[count][i%m]+=1;
        }
        
        return ret;        
    }
};
