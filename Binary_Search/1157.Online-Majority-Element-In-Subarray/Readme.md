### 1157.Online-Majority-Element-In-Subarray
#### Binary Search
我的突破口是考虑出现频次最多的元素a，它应该有最大的概率是[left,right]区间内的majority。这个怎么判断呢？显然我们将所有出现a的位置按照从小到大的顺序列出来作为数组p，然后找到left和right能插入的位置。比如，我们找到pos1表示p里面第一个大于等于left的位置，pos2表示p里面最后一个小于等于right的位置。这样，pos2-pos1+1就是在[left,right]区间内a出现的次数。将其与threshold比较就可以判断是否满足题意。

如果a不合题意，那么数组里剩余元素的总数total就减少了pos2-pos1+1个。如果频率次高的b也不符合题意，那么剩余的total会进一步减少。如果直到剩余的total小于threshold时，说明剩下的元素即使都是同一个，也无法满足题意了，此时就可以直接返回-1.

#### Segment Tree
本题也可以用线段树来实现，来实现高效地对任意区间内的majority元素的查询．

模板和基本型的线段树一样。每个节点需要存放两个信息，val表示该节点所在区间的majority candidate，另外freqDiff表示这个majority candidate在该区间的频次与其他元素的频次差的“最大可能值”。这个思想来自Boyer–Moore majority vote algorithm，可以参考```169.Majority Element```来理解。基本思想就是，如果一个属于majority的元素，与任何一个不属于majority的元素，两者同时消去，那么不影响数组剩下的元素里原本属于majority的元素的地位．

假设区间d，下面二分了两个子区间d1和d2。在d1区间中的majority是val1，它的频次比其他元素多了diff1。同理在d2区间中的majority是val2，它的频次比其他元素多了diff2.首先我们要明确一个概念，d的majority一定只能是val1和val2中的一个。注意我们对于majority的定义是区间内频次大于50%的元素。显然，如果任何一个元素在两个子区间中都不占50%多数，那么在整个大区间中肯定也不会占50%多数。那么我们如何从d1和d2两个子区间的信息里得到区间d的majority呢？
1. 如果val1==val2，那么毫无悬念，区间d的majority就是val1（或者val2）。它在整个区间里的频次优势或达到```diff = diff1+diff2```.
2. 如果va1l!=val2，我们需要两个中间选择一个。   
    (1) 如果diff1>diff2，则val1相比于val2更有可能是整个区间的majority。但是注意，不一定表示val1就一定真的是majority，因为这个区间可能根本没有majority，所以val1只是best majority candidate。那么对于val1而言，它在d区间内的频率优势如何计算呢？我们取diff的最大可能值：```diff1-diff2```.注意这是一个上限，即认为在d2区间内除了val1就是val2.只有这种情况下，val1才会继续保有最大的正数diff，即确立自己majority的地位。     
    (2) 反之，如果diff1<diff2，那么我们就认为val2是整个区间的best majority candidate，对应的频率优势是```diff = diff2-diff1```.   

通过上面递归的思想，我们就可以建立起一棵完全二叉树．每个节点代表的一个区间，并且记录了这个区间里的majority candidate的值val，diff表示在该区间内val的频次与非val的频次之差．再次强调，val不见得真的是该区间的majority。

我们基于这棵线段树，设计```queryRangeMajority(root,a,b)```来寻找区间[a,b]内的best majority candidate的数值val。这个query函数的思想和建树时候的递归逻辑一模一样。然后我们需要校验这个val是不是“真”的。怎么做呢？我们提前用hash表来存储所有数值是x的元素的index。用二分法在这些index中找到a和b的位置，这两个位置之差从而就可以知道[a,b]之前到底有多少个val。用这个数目与threshold来比较返回答案。

[Leetcode Link](https://leetcode.com/problems/online-majority-element-in-subarray)
