### 1028.Recover-a-Tree-From-Preorder-Traversal

我们知道，用树的先序遍历可以唯一地重构出这棵树来。这在```297.Serialize and Deserialize Binary Tree```中曾经提到过。但在那道题里面，先序遍历的序列化需要包括所有的空节点。在本题所给出的先序遍历里，并没有指明空节点，但是提供了另一个信息：每个节点的深度。那我们可以利用这个条件来实现相似的重构。

首先我们先预处理一下字符串，使得其变成一个节点数组nodes，每个节点元素包含了value和depth两个信息。

我们设计递归函数DFS(cur)，表示构造以nodes[cur]为根的子树。先序遍历的最大特点是，任何子树序列的第一个元素cur一定是该子树的root。然后，通常情况下，第二个元素cur+1就是左子树的根。但是也有可能root的左节点是空，这样的话第二元素就不是左子树的根（因为空节点不会计入序列）。那么如何判断呢？就看它们的深度信息就可以了：
```cpp
TreeNode* root = new TreeNode(nodes[cur].value);
if (nodes[cur].depth+1 == nodes[cur+1].depth)
  root->left = DFS(cur+1);
```
那么如何知道root的右节点在什么位置呢？只要查看一下左子树有多大即可，假设是leftNum这么多：
```cpp
if (nodes[cur].depth+1 == nodes[cur+leftNum+1].depth)
  root->right = DFS(cur+leftNum+1);
```
怎么知道左子树的大小leftNum是多少呢？可以再把左子树扫一遍。不过这样的时间复杂度就是o(N^2)了。比较高效的算法就是在构造左子树的时候，顺便把左子树的大小给算出来。所以我们设计```TreeNode* DFS(int cur, int& num)```，其中num返回的是以cur为根的子树的大小。显然有
```
num = leftNum+rightNum+1;
```
其中leftNum和rightNum又都是继续递归的产物。

那么递归算法的边界条件是什么？其实不用特地写边界条件。当遍历到叶子节点的时候，两个if语句的条件就保证递归不下去了。
