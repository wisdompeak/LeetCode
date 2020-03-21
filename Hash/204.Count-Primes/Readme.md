### 204.Count-Primes

用倍数筛除法去除所有已知质数的倍数。最高效的容器是bool型的vector
```cpp
vector<bool>q(n,true);
for (x=2; x<=sqrt(n); x++)
{
   if (q[x]==false) continue; 
   for (int i=2; x*i<n; i++)
     q[x*i]=false;
}
```
然后检查从2到n-1里仍然标记为true的元素数目。    

注意，x的判断范围是从2到sqrt(n)即可，不需要遍历到n。


[Leetcode Link](https://leetcode.com/problems/count-primes)