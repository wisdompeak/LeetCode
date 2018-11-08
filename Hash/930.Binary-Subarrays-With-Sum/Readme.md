### 930.Binary-Subarrays-With-Sum

此题是考察对Hash的一个妙用．

正确的思路是：我们遍历每一个元素j，令其为满足条件的array结尾，然后考虑它的起点i可以在哪里？起点i如果有多个方案，那么result就可以累加上这么多．

如何确定i的位置呢？我们我们会从A[j]开始往前数，数完Ｓ个为1的元素，那么再之前有多少个0，就说明i有多少个选择．那么我们真的要往前遍历数出S个１来吗？显然会费事．于是很自然地想到用前缀和的思想．

我们用Map[k]表示，数组Ａ前缀恰好有k个１的位置，其之后会紧跟着有多少个0．

假设遍历到j位置，累计有count个1，那么我们需要定位到前缀累计有count-S个１的位置，其之后有多少个紧跟着的0，比如说有M个，就说明起点i有多少M+1个方案．这里注意，如果没有紧跟着的0,也算是一种方案．

构造这个预处理字典的代码是：
```cpp
int count = 0;
Map[0] = 1;
for (int i=0; i<A.size(); i++)
{
    count+=A[i];
    Map[count]++;
}
```
最终的结果是：
```cpp
int count = 0;
int result = 0;
for (int i=0; i<A.size(); i++)
{
    count+=A[i];
    result+=Map[count-S];
}
return result;
```
