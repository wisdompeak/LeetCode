### 006.ZigZag-Conversion

观察这个数列的周期性。一个周期的元素数目```M=numRows*2-2```，因此这个数列的周期数目是```N=(len(s)-1)/M+1```。注意这种根据M计算Ｎ的的技巧。在CUDA编程中，确定block数目的计算和此很相似。

在每个周期中，第一行是第０个元素，第二行是第１和M-1个元素，第三行是第２和Ｍ-2个元素，直至最后一行是第numRows-1个元素。所以我们只要按行遍历，在每一行中将Ｎ个周期里对应该行的数字都找出来。大致的程序架构是：
```cpp
for (int i=0; i<N; i++)
   result+=s[M*i];
//以上是第0行
for (int j=1; j<ｎｕｍRows-1; j++)
｛
　　ｆｏｒ (int i=0; i<N; i++)
    {
      result+=s[M*i+j];
      result+=s[M*i+M-j];
    }
｝
//以上是第1到第numRows-2行
for (int i=0; i<N; i++)
   result+=s[M*i+numRows-1];
//以上是第numRows-1行
```
需要注意的是，以上对s的访问可能会有越界的风险（主要是针对最后一个周期），需要提前判断一下。


[Leetcode Link](https://leetcode.com/problems/zigzag-conversion)
