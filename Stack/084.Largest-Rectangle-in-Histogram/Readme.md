### leetcode-84-Largest-Rectangle-in-Histogram

此题是单调栈的经典应用。对于每个位置height[i]，找出它的prevSmaller和nextSmaller，那么中间的区间，就可以构建一个以height[i]为高的矩形。

比较笨的方法就是写3-pass。第一遍是用单调栈求出所有每个元素i的prevSmaller[i]。再逆序遍历一遍，求出每个元素i的nextSmaller[i]。最后一遍计算```area[i] = height[i]*(nextSmaller[i]-prevSmaller[i]-1)```.

高级一点的方法只需要1-pass。维护一个递增的单调栈。当新元素i比栈顶元素小时，说明栈顶元素的nextSmaller就是i，而栈顶元素的prevSmaller就是栈的次顶元素。

#### 其他的技巧：  

在height数组末添加元素0，是为了保证最后强制回溯。在height数组首端添加元素0，是为了便于处理s.pop()之后栈为空的特殊情况；这样处理后永远不会栈空。


[Leetcode Link](https://leetcode.com/problems/largest-rectangle-in-histogram)
