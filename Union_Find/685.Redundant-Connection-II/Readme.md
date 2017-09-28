### 685.Redundant-Connection-II

题意说了，只有一个edge有问题，要把它找出来。这多余的一个edge究竟会如何影响一个valid的tree呢？

首先，它可能造成某个节点会有两个parent。如果我们发现一个节点A（并且只可能有一个）的parent有两个，那么我们就可以把目标迅速缩小到A和它的这两个“父节点”之间的edges，称之为candA和candB。最终的答案必然是二选一。我们的策略是断开candB，根据剩馀的edges来尝试构造这棵树。

如果在重构的过程中（即遍历edges的过程），我们没有遇到“成环”的情况，说明什么？说明我们断开candB的决策是对的，答案就是candB。如果遇到成环的情况，那么说明决策错误，答案应该是candA。

当然，以上前提是candA和candB非空。如果candA和candB是空的，即这些节点中并没有dual parent的情况，那么本题其实就退化成了684.Redundant-Connection-I，只需要检验这些edges是否成环就行了，也就是说，答案只要输出当前使成环的那个edge就行。
