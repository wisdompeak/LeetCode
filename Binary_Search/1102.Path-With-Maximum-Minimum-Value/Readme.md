### 1102.Path-With-Maximum-Minimum-Value

#### 解法1：二分搜索

我们想，如果这个maximum score是ｘ，那么意味着存在一条路径，里面不能有任何小于ｘ的格子。因此，如果给定ｘ，我们尝试用BFS的方法从左上角走到右下角，约定不能经过任何小于x的格子。如果能抵达，说明至少存在一条成功的路，其沿途元素都不会小于ｘ，故x是一个可行解，我们可以调高对maximum score的预期。相反，如果不能走到，说明从左上到右下肯定会被一系列小于ｘ的格子给阻断了，因此我们对于maximum score的预期必须下调，至少得小于ｘ．

所以二分的策略就非常清楚了：
```cpp
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

#### 解法2：Dijkstra
此题还可以用Dijkstra来解决，不过这是一个与常规Dijkstra问题完全对偶的场景。

Dijkstra通常用在求最短路径的问题，在非负边权的图里，经过的节点越多，往往意味着路径会更长。所以在小顶堆的PQ中越早弹出来的节点，对应的就是该节点的最短路径。

本题反其道而行之，求的是一个“最长路径”的问题。但这道题定义的“路径长度”不是元素和，而是沿途元素里面的最小值。所以经过的格子越多，“路径长度”反而会越小。所以结合大顶堆（而不是通常的小顶堆），也能够将这道题解出来。

注：此题和[1631](https://github.com/wisdompeak/LeetCode/tree/master/Union_Find/1631.Path-With-Minimum-Effort)非常相似。

[Leetcode Link](https://leetcode.com/problems/path-with-maximum-minimum-value)
