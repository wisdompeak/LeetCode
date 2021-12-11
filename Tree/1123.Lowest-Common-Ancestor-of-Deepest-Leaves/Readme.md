### 1123.Lowest-Common-Ancestor-of-Deepest-Leaves

提前遍历整棵树做预处理，记录整棵树最深的深度maxDepth，以及总共有多少个深度是maxDepth的节点deepCount. 

然后第二次遍历整棵树，从下往上查看每个节点包含多少个maxDepth的叶子节点。当找到第一个数目是deepCount的节点时，说明它的子树下面包含了所有的deepest leaves，这就是答案。
