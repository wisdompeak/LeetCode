### 333.Largest-BST-Subtree

首先，看清题意，A subtree must include all of its descendants.

要判断一个root是否代表了一颗BST，有三个条件：    
1. 其左子树也是BST（或者NULL）
2. 其右子树也是BST（或者NULL）
3. 其根节点小于左子树的最大值，并且根节点大于右子树的最小值。
千万不要遗忘第三个条件。

所以，我们在构造DFS函数判断一个root是否为BST的时候，要带上这个root所表示的子树的最小值和最大值。
```cpp
int DFS(TreeNode* root, int& mmin, int& mmax)
```
怎么写这个DFS函数呢？    

首先边界条件：if (root==NULL) return 0. 那么对于NULL，怎么返回mmin和mmax呢？这里暂时不考虑。

其次我们就可以放心地为左右子树分别递归调用了
```cpp
int n1 = DFS(root->left, left_min, left_max);
int n2 = DFS(root->right, right_min, right_max);
```
子树的返回值可以是-1表示该子树非BST，也可以是0表示该子树是NULL（合法），或者是正整数表示该子树BST的大小。

什么时候让DFS(root)返回是BST的消息呢？根据之前归纳的三点：
```cpp
if ((n1==0 || n1>0 && left_max<root->val) && (n2==0 || n2>0 && right_min>root->val))
  return n1+n2+1;
```
可见这样就巧妙地将子树是否为NULL区分对待。那么如何返回mmin和mmax呢？同样也需要对NULL区别对待：
```cpp
  mmin = n1==0? root-val:left_min;
  mmax = n2==0? root-val:right_max;
```
剩余的所有情况下, 返回-1，则mmin和mmax是什么都无所谓了。
