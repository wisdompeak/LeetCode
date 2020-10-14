### 297.Serialize-and-Deserialize-Binary-Tree

#### 解法1：
##### 编码
本题按照leetcode介绍的编码方式。

构建队列，按照BFS逐层遍历二叉树，遇到非NULL节点就记录数值，遇到NULL就记录'#'，每个节点之间用','分开。遍历到队首的非NULL节点，其两个子节点都会加入队列；对于队首的NULL节点，则跳过不加入元素。

整个编码过程和BFS遍历过程没有太大区别。


##### 解码
解码的时候，先将整个编码字符串根据,分隔,构建一个指针数组，每个数组元素对应一个节点指针，这和编码过程中的队列类似。

设置初始指针i=0表示当前父节点,j=1表示当前子节点。

对于父节点q[i],对应的两个子节点必为q[j]和q[j+1]，此时只要将q[i]的left和right分别指向它们(即j和j+1)即完成了父子关系的构建． 注意此时如果q[i]为空,根据编码原则说明q里面并没有子节点被记录，故继续i++直到找到非NULL的节点，作为j和j+1的父节点。

技巧：
1. 把数字转化为字符串 to_string(num) 会自动处理负号
1. 把字符串转化为数字 stoi(str) 也会自动处理负号


#### 解法2：
编码可以用preorder遍历的方法递归得到，代码非常简洁：
```cpp
    string serialize(TreeNode* root) 
    {
        if (root==NULL) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);        
    }
```
得到的一定是唯一的序列字符串。

解码的时候首先将各个节点通过逗号的间隔抽取出来。重建的时候也是要设计递归。
```cpp
    TreeNode* DFS(vector<string>&q, int a)
    {
        if (q[a]=="#") return NULL;
        TreeNode* root = new TreeNode(stoi(q[a]));
        TreeNode* left = DFS(q,a+1);
        int leftSize = getSize(left);
        TreeNode* right = DFS(q,a+1+leftSize);        
        root->left = left;
        root->right = right;
        return root;
    }
```
需要额外一个getSize函数来计算这个子树共有多少个元素。或者在DFS的返回值里添加一个信息，表示该子树下的节点总数。

#### 解法3：
在解法2的基础上，有一个技巧可以避免额外调用getSize. 我们将所有节点都放入一个队列之中。每次的DFS其实都是从该队列中弹出首元素作为子树的根；然后构建左子树；再构建右子树。当我们试图构建右子树的时候，其实队列中的首元素就已经是右子树的根了。

[Leetcode Link](https://leetcode.com/problems/serialize-and-deserialize-binary-tree)
