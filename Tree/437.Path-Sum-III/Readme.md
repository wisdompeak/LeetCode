### 437.Path-Sum-III

#### 方法1

此题是112,113的follow up。不要求path一定是从root到leaf。

在这种情况下，每个节点都有可能是path的起点。所以需要遍历树的所有节点，对每个节点都寻找pathSum(node,sum)。

另外，(root->val==sum)并不意味着path的终点，如果子树还有和为零的路径，也合题意。所以遇到这种情况，还要进一步加上左右子树路径和为0的子问题。
```cpp
    int pathSumNum(TreeNode* node, int sum)
    {
        if (node==NULL) return 0;
        if (node->val==sum) return 1+pathSumNum(node->left,0)+pathSumNum(node->right,0);
        return pathSumNum(node->left,sum-node->val)+pathSumNum(node->right,sum-node->val);
    }
```    

#### 方法2

突破点:任何一条从A点到B点的,和为sum的路径,可以等效为从root到B的路径和,减去root到A的路径和.

所以我们考察B点时,将此时从root到B的路径和curSum,减去target,查看这个差值是否存在一个Hash表中.这个Hash表存储的是从root到任何B以前的点的路径和.因此更新结果的计数器只需要```count+=Map[curSum-target]```

注意,这个DFS需要回溯.即向下递归时需要想Hash表中添加```Map[curSum]+=1```,而向上返回时需要删除这个记录即```Map[curSum]-=1```

此外,需要注意的边界条件是:在最初始需要设置```Map[0]=1```,即什么都不拿的话也算target==1的一种方法.上述的DFS依赖于这个边界条件.


[Leetcode Link](https://leetcode.com/problems/path-sum-iii)