### 2866.Beautiful-Towers-II

我们很容易想到，遍历每个位置p，假想它作为peak（自然设置为maxHeights[p]），那么我们可以得到的最大面积是多少。

如果p是peak，那么它左边必然是一个单调递增的序列。我们逐个来扫描这些位置。
1. 如果maxHeights[i]始终是递增的，那么我们每次只需增加mexHeights[i]即可。
2. 如果maxHeights[i]比之前的位置矮，那么i之前的位置受到新的制约，必须退回之前所盖的高度，转而盖成与maxHeights[i]平齐的高度。显然，这样的“回退”可能不止一次。

这些思考都让我们联想到单调栈。我们应该试图在stk里存放单调递增的高度（实际上是对应的位置）。当前述的情形2发生时，即`maxHeights[stk.top()] > maxHeights[i]`时，我们令
```cpp
p1 = stk.top();
stk.pop();
p2 = stk.top();
```
我们对栈顶元素p1退栈时，要“回退”的面积其实是`(p1-p2)*maxHeights[p1]`，也就是说，之前[p2+1, p1]这一段最理想的状态是都与maxHeights[p1]平齐，这样既不超过p1的约束，也最大化了总面积。

同理，退完p1之后，如果发现`maxHeights[p2] > maxHeights[i]`时，我们依然要继续退栈，同上，退出一段与maxHeights[p2]平齐的高度。

当所有的回退完成之后，我们保证了maxHeights[i]高于当前的栈顶元素（假设为pp），那么意味着从[pp+1,i]这段区间我们都可以最大化设置为maxHeights[i]。

此时的总面积就是从左往右截止到i位置，为了保持递增关系，能够得到的最大面积，记做left[i].

同理，我们将上面的过程反过来，从右往左做一遍，得到从右往左截止到i位置，为了保持递增关系，能够得到的最大面积，记做right[i].

那么以i为peak的最大总面积就是`area[i] = left[i]+right[i]-maxHeights[i]`.

我们在所有的area[i]取全局最大值即可。

此题的解法和`084.Largest-Rectangle-in-Histogram`非常类似。

