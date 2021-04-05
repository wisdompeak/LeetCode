### 699.Falling-Squares

#### 解法1：使用Hash容器

此题考查了对Hash结构（比如说Map和Set）的迭代器的操作。

设置一个有序hash表，map<int,int>Map，其中的key表示在横轴上某个x的位置，value表示从这个x开始往右直至遇到下一个邻接x位置之间的高度（这个高度在这两个位置之间必须是平整的）。在不断读入positions的过程中，来更新这个Map。

对于一个新引入的square，我们考察它的左右边界left,right在这个hash表中的位置（找最近邻元素的迭代器）
```cpp
auto ptri = Map.lower_bound(left);
auto ptrj = Map.upper_bound(right);
```
注意得到的两个边界迭代器的意义。ptri表示处于left或其靠右的第一个迭代器。ptrj表示在right靠右的第一个迭代器。

根据题意，处于[ptri,ptrj)的那些hash元素都将被取代（抹平），换成这个新square的信息。这个新square叠加上去后的高度等于这些hash元素的最大值加上新square自身的高度。但是注意，以上对于 ```ptri->first == left```时成立；但是对```ptri->first > left```时，我们必须把ptri之前的那个元素也考虑上，即 prev(ptri,1)。
```cpp
auto ptr= ptri->left==left? ptri:prev(ptri,1);
int maxH=0;
while (ptr!=ptrj)
{
    maxH=max(maxH,ptr->second);
    ptr=next(ptr,1);
}
```
以上得到了新高度。但是如何抹平之前的呢？erase命令可以删除一个前闭后开的迭代器区间。特别强调，不能用for等循环名一边通过迭代器遍历hash、一边删改迭代器。这是会出错的。
```cpp
Map.erase(ptri,ptrj)
```
接下来要跟新，即在Map里新加入一个区间。显然对于新sqaure的左边界，会引入：
```cpp
Map[left]= maxH+h;
```
特别注意：对于新sqaure的右边界，同样也可能会引入新生成的边界。比如，当新square比较小，那么Map[right+1]应该是之前 prev(ptrj,1)对应的数值。这个数值必须在对Map做迭代器删改之前保留下来。

#### 解法2：使用线段树

本题的线段树解法和```218.The Skyline Problem```类似，都要用到离散化+懒标记。

数据结构：和218类似，我们定义SegTreeNode.info表示该节点所对应的区间的最大高度。tag表示该区间的高度是否都是一致的。如果是的话，tag标记为true，我们就可以省去对下层更细区间的查询。

离散化：和218类似。同样，对于底边范围是[i:j]的正方形，我们实际查询和更新的区间是[i:j-1]。也就是说，对于线段树中的每个子节点，info代表的是```[i:i+1)```这段左闭右开的区间的高度。

区间查询：我们需要在某个线段树子树内查询指定区间[a,b]的最大高度。同样分为几种情况讨论：
1. 如果节点区间与[a,b]互斥，那么返回0（无限小）
2. 如果节点区间被包含于[a,b]之中，那么在本题题境里面，不论是否有懒标记，都无需再查询更下层的区间，直接返回node->info。（这是因为从上往下走的过程中，无论query还是update，我们都不会越过懒标记的节点。如果越过懒标记的节点，必然伴随着pushdown将懒标记下移，并把下层的节点准确地更新了。）
3. 其他情况下，需要递归处理两个区间，返回```max(queryRange(node->left, a,b), queryRange(node->right, a,b))```.特别注意，在进行递归之前，需要pushdown（即如果tag已经标记，需要取消该节点的标记，并且将影响传播到它的两个子节点）。

区间更新：我们需要在某个线段树子树内将指定区间[a,b]的高度统一设置val。同样分为几种情况讨论：
1. 如果节点区间与[a,b]互斥，那么直接返回。
2. 如果节点区间被包含于[a,b]之中，那么在本题题境里面，说明整个区间的info一定都是要更新的。那么无需再更新下层的区间，直接更新node->info后返回。注意保持懒标记。
3. 其他情况下，需要递归处理两个区间，```queryRange(node->left, a,b) && queryRange(node->right, a,b)```，然后更新node->info.特别注意，在进行递归之前，需要pushdown（即如果tag已经标记，需要取消该节点的标记，并且将影响传播到它的两个子节点）。

主程序：
```cpp
        for (auto& rect: positions)
        {
            int a = pos2idx[rect[0]], b = pos2idx[rect[0]+rect[1]];
            int h = queryRange(root, a, b-1);
            updateRange(root, a, b-1, h+rect[1]);
            cur = max(cur, h+rect[1]);
            rets.push_back(cur);
        }
```        

[Leetcode Link](https://leetcode.com/problems/falling-squares)
