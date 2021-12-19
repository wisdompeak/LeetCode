### 2102.Sequentially-Ordinal-Rank-Tracker

#### 解法1
本题乍看之下，需要一个既能自动排序（像Set）、又可以按照index来读取内容（像数组）的数据结构。通常情况下这种数据结构是很难得到的。但是本题暗藏的玄机在于，它并不是真正需要随机按index来读取数据，而是固定按照递增的顺序来读取。这就意味着，每次add和get的操作，最多只会影响待读取内容的指针往左右移动最多一位即可。

具体的说，我们维护一个有序集合的迭代器，指向当前的第i个位置（即下一个get所需要读取的index）。如果有新加入数据，并且新数据小于指针的数据，那么我们就可以将迭代器前移一位（用prev函数），这样依然指向的是第i个数据；如果新数据大于指针的数据，那么迭代器就不需要变化。遇到get操作时，就读取指针当前指向的内容，并且把迭代器后移一位即可（用next函数）。

注意为了能使得有序集合按照「分数」从大到小、「名字｜从小到大的顺序排列，我们定义set<pair<int,string>>set，其中pair的第一个分量是-score。

#### 解法2
可以直接使用pbds的数据库和find_by_order(k)这个API。参见[模版](https://github.com/wisdompeak/LeetCode/blob/master/Template/RB_Tree/ordered_set.cpp).
