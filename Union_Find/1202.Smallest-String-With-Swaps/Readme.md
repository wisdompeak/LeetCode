### 1202.Smallest-String-With-Swaps

很显然，将所有有联通关系的index都union成一个连通图，那么这些index对应的字符其实就可以任意调换顺序，想像成“冒泡法”就不难理解了。

将一个连通分量内的字符串抽取出来按照字典序重新排列，然后再依次放回这些index的位置，就是答案。


[Leetcode Link](https://leetcode.com/problems/smallest-string-with-swaps)