### 543.Diameter-of-Binary-Tree

对于所有可能的diameter，本质都对应了一个节点作为“拐点”。所以本题的基本思想就是遍历所有的节点，对每个节点找最长的左子树-根-右子树的路径。

如果从上往下地DFS，要避免这种情况：先算出根节点的路径，再计算左子树和右子树的路径。因为在算根节点的最长路径时，必然会考察其左子树和右子树；这样，如果再计算左子树和右子树的最长路径，必然会浪费之前的计算结果。所以我们应该设计这样的DFS函数：
```cpp
int DFS(TreeNode* root)
{
  int info_left = DFS(root->left);
  int info_right = DFS(root->left);
  result = max(result, f1(info_left,info_right));  // 以该节点为拐点的最长路径
  return f2(info_left,info_right);  // 设计的返回值
}
```
这样本质上就实现了自底向上的遍历。那么我们需要提取什么样的信息呢？我们其实需要一个节点到叶子节点的最长路径即可。
```cpp
    int LongestPathToLeaf(TreeNode* root) // 返回以该节点为顶点到叶子节点的最长路径
    {
        if (root==NULL) return 0;        
        int left = LongestPathToLeaf(root->left);
        int right = LongestPathToLeaf(root->right);
        result = max(result,left+right+1);  // 以该节点为拐点的最长路径
        return max(left,right)+1;  // 以该节点为顶点到叶子节点的最长路径
    }
```    


[Leetcode Link](https://leetcode.com/problems/diameter-of-binary-tree)