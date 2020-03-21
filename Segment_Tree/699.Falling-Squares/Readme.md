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

相比于 715.Range Module 使用的标准线段树模型，此题只需要对标准模型进行很小的改动即可适用。

也即是每个线段的status不再是一个二值的状态，而是代表了```[begin,end)```区间里最大高度。每次处理一个正方形(x,y,d)，首先用```getStatus(x,y)```得到该区间内的最大高度maxH，然后在该相同的区间内```setStatus(x,y,maxH+d)```即可。整颗线段树的维护非常直观。

相比与715，线段树模型的改动之处是：715题的setStatus里，```status = left->status && right->status```，现在改为 ```stuats = max(left->status, right->status)```即可。


[Leetcode Link](https://leetcode.com/problems/falling-squares)