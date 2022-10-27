### 1499.Max-Value-of-Equation

如果我们固定j点，那么原题就是求```max{yi+yj+xj-xi} = max{-xi+yi} + xj+yj ```.也就是要在|xi-xj|<k的范围内，找到一个i点，使得-xi+yi最大。这就是一个典型的sliding window maximum，标准解法使用双端队列，时间复杂度是o(N).

注意，这里的sliding window并不是固定长度的，我们保持的是一个满足首尾元素|xi-xj|<k的窗口。队列中保持递减的序列。任何新进来的元素，如果-x+y比队尾元素要大，说明队尾的元素就不再有任何利用的价值（又旧又小，永远不会被用到），那么队尾元素都可以弹出。
