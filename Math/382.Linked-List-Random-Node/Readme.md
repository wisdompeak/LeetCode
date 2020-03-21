### 382.Linked-List-Random-Node

这是一个非常实用的随机数生成方法，叫做 reservoire sampling。不需要事先遍历所有的元素，也不需要记录任何元素。

假设只有一个元素a，输出结果就是result = a。

假设读入第二个元素b，让result取一半的概率变为b：于是此时result相当于有一半概率是a，一半概率是b。

假设读入第三个元素c，让result取1/3的概率变为c：于是此时result相当于1/3的概率是c，那么剩下非c的概率里a、b各是多少呢？根据前面的分析，各一半。所以result相当于1/3的概率是b，1/3的概率是c。

假设读入第四个元素d，让result取1/4的概率变为c：于是此时，根据前面的分析不难推广，result各有1/4的概率等于a,b,c,d。

于是算法就很容易归纳了。

更常见的问题是，如何得到k个均匀分布的随机数？只要把result当做一个能容纳k个元素的reservoire。每次遇到的新元素以 k/i的概率保留，再在这个reservoir里以均匀概率选取一个替换成新元素就行。可以证明，当所有的元素遍历完之后，剩下的result里就是以均匀概率选取的k个数。

类似的题是：398.Random Pick Index


[Leetcode Link](https://leetcode.com/problems/linked-list-random-node)