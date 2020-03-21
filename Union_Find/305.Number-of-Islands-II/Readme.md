### 305.Number-of-Islands-II

设置所有点的初始Father为-1，表示海洋。

然后依次遍历每一块新陆地，最开始标记它的Root为自身，然后count++。依次考察这个新陆地相邻的四块：如果相邻的是陆地，并且新陆地和老陆地的Root不同，那么说明这是需要合并的两个集合，于是count--，并且将新陆地与旧陆地进行Union。最终实时输出count。

有一个corner case是，positions里面可能会包含重复的同一块陆地。所以每遍历一块新陆地的时候，得先看看是否已经访问过了，已经访问过了就不要再重新标记Root，否则会出错。


[Leetcode Link](https://leetcode.com/problems/number-of-islands-ii)