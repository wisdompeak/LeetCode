### leetcode-84-Largest-Rectangle-in-Histogram

#### 此类是贪心法的典型题。
----------
贪心法的原则是维护一个递增（严格的说是非递减）的栈序列s，s里面是所给数组元素的index（注意不是数组元素本身）。当下一个元素满足递增的要求时，入栈：
```c
if (height[i]>height[s.top()]) 
  s.push(height[i]);  
```
当下一个元素不满足递增的要求时，就退栈处理栈顶的一些元素，使得即将入列的元素依然满足递增关系。退栈处理的过程中可以方便地考察那些退栈元素所围成的最大面积。其高度易知是height[s.top()]，但宽度是什么呢？注意是和次顶元素的位置有关：  
```cpp
while (height[s.back()]>height[i])
{
  Height = height[s.top()];  
  s.pop(); // 提取次顶元素的位置  
  result = max(result, Height * (i-s.top()-1);  
}
```
注意如果写成以下就是错误的:  
```c
result = max(result, height[s.top()] * (i-s.top());  
```


原因是次顶元素和栈顶元素可能在index上并不是相邻的，中间可能隔着一些已经被处理掉的大数。因此在考虑当前的栈顶元素围成的面积，应该包括这些位置，所以其宽度不仅是i-s.top()，而要更大。  

其他的技巧：  
----------
在height数组末添加元素0，是为了保证最后强制回溯。在height数组首端添加元素0，是为了便于处理s.pop()之后栈为空的特殊情况；这样处理后永远不会栈空。


[Leetcode Link](https://leetcode.com/problems/largest-rectangle-in-histogram)