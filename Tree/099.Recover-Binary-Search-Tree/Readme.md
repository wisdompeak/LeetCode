### 099.Recover-Binary-Search-Tree

因为是BST，所以按先序遍历访问下来应该是一个递增的数列。如果一个递增的数列里出现两个数字的对调，那么会有两个尖峰。显然，第一个尖峰的顶和第二个尖峰的谷，就是被掉包的那两个数字。

本题按先序遍历访问BST（采用DFS递归的方法）。初始化三个公共变量
```cpp
TreeNode* first=NULL;
TreeNode* Second=NULL;
TreeNode* CurMax=new TreeNode(INT_MIN);
```
在遍历过程中，CurMax永远存储的是上一次访问的节点，理论上是一个不断增大的值。

如果第一次出现当前访问的节点 node->val < CurMax->val，说明遇到了第一个尖峰，那么根据之前的分析，first=CurMax 即为第一个掉包元素。怎么判断这是第一个尖峰呢？只需要看first==NULL就行。别忘了，这一回合后的CurMax应该设置为node。

如果第二次出现当前访问的节点 node->val < CurMax->val，说明遇到了第二个尖峰，那么根据之前的分析，second=node，即为第二个掉包元素。

这里还有一个关键点：如果整个树的两个掉包元素是相邻的，那么整个遍历只会找到一个尖峰。所以这里未雨绸缪的技巧是，在处理第一个尖峰时，同时把第二个掉包元素也设置 second==node. 后续如果找到了第二个尖峰，则second会被覆盖。


[Leetcode Link](https://leetcode.com/problems/recover-binary-search-tree)