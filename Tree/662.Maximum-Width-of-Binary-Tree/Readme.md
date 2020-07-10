### 662.Maximum-Width-of-Binary-Tree

利用二叉树的这个性质：若一个节点的深度是level，在该层的序号是order，则其左子树的深度是level+1且在该层的序号是```order*2```，其右子树的深度是level+1且在该层的序号是```order*2+1```。

我们可以用BFS的思想，对这棵树做层级遍历。那么每层的的第一个节点和最后一个节点的序号之差就代表了这一层的宽度。数据结构的使用上，deque比queue更方便一些。

本题需要优化的第一个地方是：随着层级的深入，节点序号的数值也会膨胀，可以想象，当超过128层的时候，序号连long long都无法记录了。优化的方法是：如果某一层只有一个节点的话，我们可以把那个节点看做成根节点，并将其序号reset成为0. 这样它之后层级的节点序号就又变小了，同时也不影响最终结果。

[Leetcode Link](https://leetcode.com/problems/maximum-width-of-binary-tree)
