### 099.Recover-Binary-Search-Tree

因为是BST，所以按先序遍历访问下来应该是一个递增的数列。如果一个递增的数列里出现两个数字的对调，那么会有两个尖峰。显然，第一个尖峰的顶和第二个尖峰的谷，就是被掉包的那两个数字。

本题按先序遍历访问BST（采用DFS递归的方法）。初始化三个公共变量
```cpp
TreeNode* first=NULL;
TreeNode* Second=NULL;
TreeNode* CurMax=new TreeNode(INT_MIN);
```
在遍历过程中，CurMax永远存储的是上一次访问的节点，理论上是一个不断增大的值。

如果第一次出现当前访问的节点 node->val < CurMax->val，说明遇到了第一个尖峰，那么根据之前的分析，first=CurMax 即为第一个掉包元素。怎么判断这是第一个尖峰呢？只需要看first==NULL就行。之后，CurMax需要重置为正常的node。

这里还有一个关键点：如果整个树只有两个元素且被掉包，则运行完这段之后就会退出程序，无法得到second的值。所以这里未雨绸缪的小技巧，同时设置了second==node.

如果第二次出现当前访问的节点 node->val < CurMax->val，说明遇到了第二个尖峰，那么根据之前的分析，second=node，即为第二个掉包元素。
