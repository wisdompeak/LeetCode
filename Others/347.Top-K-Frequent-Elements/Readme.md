### 347.Top-K-Frequent-Elements

#### 解法1： 二分搜值

#### 解法2： qucik select
此题另外一种常见做法是quick select，用o(N)的时间来实现寻找第k大元素（即频率）。具体的思想和quick sort很像，每次找一个pivot，根据pivot的值用三指针算法把整个arr重新调整为三部分（小于pivot、等于pivot、大于pivot）。然后根据各部分数量与k的关系，选择下一步递归需要处理哪个部分。

找到这个频率值f之后，再扫一遍全部所有的频次，凡是频次大于f的元素就是答案。
