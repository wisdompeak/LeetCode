### 005.Longest-Palindromic-Substring

### 解法1：
考虑以每个字符为对称中心（或者为对称中心线左边的字符），同时往左往右推广，看看将回文半径最长能推至哪里。这个解法比较好写，复杂度是o(N^2)

### 解法2：KMP
有个更好的线性时间的Manacher算法，可以参考 https://segmentfault.com/a/1190000003914228 这里简单的介绍一下算法。

我们将s = aaaba，填充"#"得到 t = #a#a#a#b#a#，我们令数组P[i]表示以t[i]为对称中心的最大回文半径（不包括t[i]本身）。这样做就是为了解决回文长度奇偶性的问题。在字符串t中，最大的P[i]就代表了最长的回文半径。

如今我们期望能以线性的速率得到P[i]，而不是按照解法1那样，对于每个i都要往两边扩展。所以我们思考，如果我们已知了P[0],..,P[i-1]，该如何得到P[i]呢？

我们维护两个变量，maxRight表示在所有P[0],...,P[i-1]为中心的完整回文串中，能够到达的最右边的位置。对应这个回文串的中心，就是maxCenter. 故有```maxRight = maxCenter+P[maxCenter]```.

我们在考虑i的时候，如果i>=maxRight，我们就按照解法1，老老实实地往两边扩展，从半径为0开始，探索P[i]。

如果i<maxRight，我们其实对P[i]可以有一个初步的估计，不用从零开始。这个估计就是```min(P[maxCenter*2-i], maxRight-i)```。可以这么考虑：令 ```j = maxCenter*2-i```是与i关于maxCenter对称的点。见下图。
```
X  X  X  {X  X  X  X  X  X  X  X  X  X  X}  X  X  X  X  X
      ---------------
             j          ctr          i
```
因为maxCenter对应的回文串非常长，（至少部分）包裹了以j为中心的回文串，必然也会包裹了以i为中心的回文串。因为i和j完全关于maxCenter对称，所以以i为中心的回文串半径至少该与以j为中心的回文串半径相同（或者说这两个回文串整体都相同）。当然，这也是有个前提，就是这个回文串都被包裹在以maxCenter为中心的大回文串里面。所有我们需要取```min(P[maxCenter*2-i], maxRight-i)```。

这样，我们就可以顺序地探索所有P[i]，并找到其中的最大值maxLen，和对应的i的索引maxCenter。注意P的构建是基于t的，那么如何返回基于s的那个回文串呢？其实很巧妙，输出的就是:
```s.substr(maxCenter/2-maxLen/2,maxLen)```



[Leetcode Link](https://leetcode.com/problems/longest-palindromic-substring)
