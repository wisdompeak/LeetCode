### 424.Longest-Repeating-Character-Replacement
本题的本质就是用一个滑动窗口，查找最长的sub array，使得其最多含有ｋ-1个与majority不相同的字符．这里majority指的是窗口中出现最多的那个字符．

很显然，我们需要一个hash map或者字典来存放每个字符出现的次数．在不断拓宽窗口的过程中，如果
```
窗口长度数M - majority元素的个数N > K
```
那么就需要移动左指针缩短窗口．为什么呢？因为如果只移动右指针，即使加入了majority元素，窗口内的那些非majority元素仍然多于Ｋ，使得整体无法成为一个合法的窗口．

分析：
１．为什么左指针移动之后不用更新结果？

这是因为，我们移动左指针的起因是之前s[j]的引入，它必然是一个非majority的字符（否则整个窗口应该会继续保持合法），而无论左指针弹出的是否majority元素，都不会得到更好的结果，最多持平，所以我们不需要更新结果．

２．为什么左指针移动只需要一步？

因为我们求最长的窗口，左指针的移动不用太大．事实上，只要移动左指针一步，那么整个窗口还是有机会通过移动右指针找到下一个可能的窗口．参看上面的那个公式．


[Leetcode Link](https://leetcode.com/problems/longest-repeating-character-replacement)