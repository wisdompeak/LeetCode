### 1102.Path-With-Maximum-Minimum-Value

此题是二分法的非常精彩的应用．

我们想，如果这个maximum score是ｘ，那么意味着存在一条路径，里面不能有任何小于ｘ的格子．因此，如果给定ｘ，我们尝试用ＢＦＳ的方法从左上角走到右下角．如果能抵达，说明至少存在一条成功的路，他们所有的元素都不会小于ｘ，而且ｘ还可能有提升的空间．相反，如果不能走到，说明从左上到右下被一些列小于ｘ的各自给阻断了，因此我们对于maximum score的预期必须下调，至少得小于ｘ．

所以二分的策略就非常清楚了：
```
        while (left<right)
        {
            int mid = right-(right-left)/2;                        
            if (isOK(A,mid))
                left = mid;
            else
                right = mid-1;
        }
```        
因为我们在收缩范围的时候，永远是将可行解放在闭区间[left,right]内，不可行解排除在闭区间外.所以当left和right收敛的时候，一定是一个可行解，直接返回left即可．


[Leetcode Link](https://leetcode.com/problems/path-with-maximum-minimum-value)