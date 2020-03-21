### 370.Range-Addition

#### 解法1：
此题比较简单的解法是用差分数组```diff```。```diff[i]```表示```nums[i]```比```nums[i-1]```大多少。这样如果已知```nums[i-1]```，那么就有```diff[i]=nums[i-1]+diff[i]```。本题中的三元参数```update(i,j,k)```恰好就是给出了这样的差分数组的信息：```diff[i]+=k, diff[j+1]-=k```.

#### 解法2：
此题的线段树解法比307更进了一步。307中构造的线段树，是严格的二分到底，即最低层的节点必然有```start==end```。本题中则不一定，只要```[start,end]```区间中的状态都是一样的，那么就不会有再往下子树，这样可以节省很多空间。

本题中，我们将节点的线段定义成一个左闭右开的区间```[start,end)```，个人觉得后续处理更方便些。状态```status```表示该区间内的元素的值。注意，在本题的线段树中，只有最底层节点的status才是真正有意义的。非底层节点，其区间内的值并不一致，所以没有意义，我们需要往下进一步拆分区间来探索。

这题中，我们尝试将线段树中的常用操作（method）写入线段树的类（SegTree）里面，使得类的封装性更好。注意，本题我们只需要一个setStatus的方法，其他更复杂的线段树可能会需要getStatus和remove等操作。

我们定义```void setStatus(int a, int b, int s)```表示往当前的线段树root里面，寻找一段区间```[a,b)```并将这段区间内的status设置为s。

以下是模板化的setStatus的写法，分析见注释：
```cpp
class SegTree
{
    ...
      void setStatus(int a, int b, int s)
      {
            if (a<=start && b>=end && left==NULL)   
            // 边界情况1：left==NULL表示这是底层节点，并且[a,b)包含了当前节点的整个区间[start,end)，所以可以直接操作这个区间的status
            {
                status += s;
                return;
            }
            
            // 边界情况2：[a,b)和当前节点的整个区间[start,end)完全不相交，没法做任何更新，直接返回
            if (a>=end || b<=start)         
                return;
                
            // 其他情况，说明我们无法对整个[start,end)做统一的操作，只能考察该节点的子节点。           
            int mid = start+(end-start)/2;  
            // 如果没有子节点怎么办？我们先创建子节点，子节点的status继承自父节点的status
            if (left==NULL)                 
            {
                left = new SegTree(start,mid,status);
                right = new SegTree(mid,end,status);
            }                               
            // 现在有了子节点，我们轻轻松松调用递归处理就可以了。
            left->setStatus(a,b,s);
            right->setStatus(a,b,s);
      }
}

```
将整棵线段树更新之后，本题求它所代表的所有区间内的每个元素值。我们只要用DFS的方法去遍历，读取所有底层节点的区间的status就行了。


[Leetcode Link](https://leetcode.com/problems/range-addition)