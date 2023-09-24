using LL = long long;
class Solution {
    int Father[100005];
    vector<int> next[100005];    
    unordered_set<int>primes;
    LL global = 0;    
public:    
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
        if (x<y) Father[y] = x;
        else Father[x] = y;
    }     
    
    unordered_set<int>Eratosthenes(int n)
    {
        vector<int>q(n+1,0);
        unordered_set<int>primes;
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
                primes.insert(i);                
        }
        return primes;
    }
    
    bool isPrime(int x)
    {
        return primes.find(x)!=primes.end();
    }
    
    long long countPaths(int n, vector<vector<int>>& edges) 
    {
        primes = Eratosthenes(n);        
        
        for (int i=1; i<=n; i++)
            Father[i] = i;
        
        for (auto& edge: edges)
        {
            int a = edge[0], b = edge[1];
            next[a].push_back(b);
            next[b].push_back(a);
            if (!isPrime(a) && !isPrime(b))
            {
                if (FindFather(a)!=FindFather(b))
                    Union(a,b);
            }
        }
        
        unordered_map<int,int>Map;
        for (int i=1; i<=n; i++)
            Map[FindFather(i)]+=1;
            
        for (int p: primes)
        {
            vector<LL>arr;
            for (int nxt: next[p])
            {
                if (!isPrime(nxt))
                    arr.push_back(Map[FindFather(nxt)]);
            }
            LL total = accumulate(arr.begin(), arr.end(), 0LL);
            LL sum = 0;
            for (LL x: arr)                    
                sum += x*(total-x);         
            global += sum/2 + total;
        }
                
        return global;
    }
    
};
