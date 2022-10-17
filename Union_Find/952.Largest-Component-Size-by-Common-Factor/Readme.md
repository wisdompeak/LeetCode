### 952.Largest-Component-Size-by-Common-Factor

此题一眼就能看出是Union Find的解法．任意两个数，只要有质因数相同，就能建立起联系．所以我们将所有的数a,都分解成一系列质因数Pi，将a和Pi都Union起来．最后看所有的数字经过聚类之后，最大的群的数量．

第一个版本，我们可以将100000以内的所有的质数Pi都找出来，挨个查看是否是a的因数．这比直接求a的所有质因数要快．
```cpp
        vector<int>primes = makePrimes(100000);
        for (auto p:primes) Root[p] = p;
        for (auto a:A) Root[a] = a;
        
        for (auto a:A)
        {
            for (int p:primes)
            {
                if (a%p==0 && findRoot(a)!=findRoot(p))
                    Union(a,p);                            
                if (p>a/2) break;
            }
        }
        
        unordered_map<int,int>Groups;
        for (auto a:A)              
            Groups[findRoot(a)]+=1;
            
        int result = 0;
        for (auto x:Groups)
            result = max(result,x.second);
        return result;
```
这个解法能够AC，但是比其他答案要慢得多．原因是100000以内的质数有9592个。对于每个nums[i]要check将近10000次，效率很低。

第二个版本，我们只需要求出sqrt(100000)以内的所有质数Pi，这样只有70个左右。但是如果继续按照上面的算法，如何保证得到a的所有质因数Pi并建立联系呢？其实我们只要将a不断除以它在sqrt(100000)以内的所有质因数，如果仍然大于1，那么剩下的必然是它唯一的一个大于sqrt(100000)的质因数．因为任何数不可能含有两个大于sqrt(100000)的质因数的．
```cpp
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
```        


[Leetcode Link](https://leetcode.com/problems/largest-component-size-by-common-factor)
