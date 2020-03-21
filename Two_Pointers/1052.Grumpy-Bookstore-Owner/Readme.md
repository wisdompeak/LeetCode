### 1052.Grumpy-Bookstore-Owner

此题不需要处理前缀和，直接用双指针和滑窗即可。

首先算出base，就是在不使用技能X的情况下，可以得到的满意度。然后考虑第一个长度为X的滑窗内，我们可以额外增加的满意度，加在base上之后就得到cur。

接下来就是滑动窗口。每一步会退出一个元素customers[i]，考察它对应的grumpy[i]是否是1，如果这个元素是通过技能额外增加得到的，我们就需要从cur里面减去；同时每滑动一步也会增加一个元素customers[i+X]，考察它对应的grumpy[i+X]是否是1，如果这个元素原本没有被计入，那么我们就在cur里面加上它。

整个滑动过程中最大的cur，就是答案。


[Leetcode Link](https://leetcode.com/problems/grumpy-bookstore-owner)