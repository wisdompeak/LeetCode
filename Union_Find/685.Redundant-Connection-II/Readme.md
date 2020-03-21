### 685.Redundant-Connection-II

题意说了，只有一个edge有问题，要把它找出来。这多余的一个edge究竟会如何影响一个valid的tree呢？

首先，它可能造成某个节点会有两个parent。如果我们发现一个节点A（并且只可能有一个）的parent有两个，那么我们就可以把目标迅速缩小到A和它的这两个“父节点”之间的edges，称之为candA和candB。最终的答案必然是二选一。我们的策略是断开candB，根据剩馀的edges来尝试构造这棵树。

如果在重构的过程中（即遍历edges的过程），我们没有遇到“成环”的情况，说明什么？说明我们断开candB的决策是对的，答案就是candB。如果遇到成环的情况，那么说明决策错误，答案应该是candA。重构的过程仍然可以用union find，这和68４.Redundant-Connection-I没有太大区别，只不过union两个节点的时候已经知道明确的指向关系了．

当然，以上前提是candA和candB非空。如果candA和candB是空的，即这些节点中并没有dual parent的情况，那么本题其实就退化成了684.Redundant-Connection-I，只需要检验这些edges是否成环就行了，也就是说，答案只要输出当前使成环的那个edge就行。

补充：

1.为什么不能任意断开一条边就行？考察这个例子：　0->1, 1->2, 2->1. 对于1而言有两个parent,但是如果断开0->1的话，0就成了孤悬的节点．事实上，0应该是根节点．分析可知，如果一个节点有两个parent，这两个入度线路可能有一个不是从根节点方向过来的，必须断开这个；如果两个入度线路都是从根方向来的，那么任意断开一个都是可以的．

２．有一道类似的题，给出一个二叉树的root，并且告诉你这个树里面从某个节点多飞出了一条edge连接到了其他节点上，求修复这棵树．对于这道题，因为已经告知了root，所以当你发现有两个parent的时候，删掉任意一个edge都是可以的．

但是有一个corner case，那就是如果这个多余的edge指向了root，那么整棵树里不会有任何节点拥有两个parent，这需要额外处理．


[Leetcode Link](https://leetcode.com/problems/redundant-connection-ii)