### 392.Is-Subsequence

普通的双指针解法就不再赘述。考虑follow up的问题。显然，需要提前建立关于t的一些信息的存储，方便s来查阅，用空间换时间嘛。

结合双指针解法的思路，如果在t[pos]找到了s[i]，则只需要在pos之后去寻找s[i+1]。所以提前构建映射：t的每个字符和该字符出现位置:
```cpp
Map[s[i]].push_back(i);
```
建立pos的初始位置-1. 然后遍历s[i]：在Map[s[i]]里找第一个大于pos的位置并更新pos，则之后对于s[i+1]的查找必须从t的新pos位置开始。
```
int pos=-1;
for (int i=0; i<s.size()-1; i++)
{
   int flag=0;
   for (int j: Map[s[i]])
   {
      if (j>pos)
      {
         pos = j;
         flag = 1;
      }
   }
   if (flag==0) retrun false; // 对于s[i]，在t中没有找到合适的位置
}
return true;
```


[Leetcode Link](https://leetcode.com/problems/is-subsequence)