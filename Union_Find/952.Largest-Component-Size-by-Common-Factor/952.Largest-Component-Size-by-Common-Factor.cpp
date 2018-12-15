class Solution {
    unordered_map<int,int>Root;
public:
    int largestComponentSize(vector<int>& A) 
    {            
        vector<int>primes = makePrimes(sqrt(100000));        
        for (auto p:primes) Root[p] = p;
        for (auto a:A) Root[a] = a;
        
        for (auto a:A)
        {
            int x = a;
            for (int p:primes)
            {
                if (x%p==0)
                {
                    if (findRoot(p)!=findRoot(a))
                        Union(p,a);
                    while (x%p==0) x = x/p;                    
                }                
                if (p>x) break;
            }            
            if (x>1)
            {
                if (Root.find(x)==Root.end()) Root[x] = x;
                Union(x,a);
            }
        }
        
        unordered_map<int,int>Groups;
        for (auto a:A)      
            Groups[findRoot(a)]+=1;
            
        int result = 0;
        for (auto x:Groups)
            result = max(result,x.second);
        return result;
    }
    
    vector<int>makePrimes(int N)
    {
        vector<bool>prime(N,true);
        vector<int>results;
        for (long i = 2; i < N; i++) 
        { 
            if (prime[i]) 
            { 
                results.push_back(i);                
                for (long j = i*i; j < N; j += i)                 
                    prime[j] = false;
            } 
        }
        return results;
    }
    
    int findRoot(int x)
    {
        if (x!=Root[x])
            Root[x] = findRoot(Root[x]);
        return Root[x];
    }
    
    void Union(int x, int y)
    {
        x = Root[x];
        y = Root[y];
        if (x<y) Root[y] = x;
        else Root[x] = y;
    }
};
