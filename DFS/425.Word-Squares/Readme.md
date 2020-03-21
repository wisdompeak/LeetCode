### 425.Word-Squares

此题是一个包装地非常好的DFS问题．而且你需要提前准备好一个可供DFS的库，那就是将所有prefix->words的映射．

递归的过程其实很简单．涉及build(k)表示我们要填充第ｋ行（或第k列），但其实第k行(或列)的前缀已经被前k-1行给固定好了，那就是
```cpp
for (int i=0; i<k; i++)
  prefix+= square[i][k];
```
注意，我们这里每次递归只填充行．列没有必要填充，因为行确定了，相应的列就确定了．所有的已知信息可以从行里面读取．

有了prefix，再结合之前的映射库，我们可以找到所有的候选word用于填充第k行．填好之后就可以递归调用build(k+1)了．非常简明．


[Leetcode Link](https://leetcode.com/problems/word-squares)