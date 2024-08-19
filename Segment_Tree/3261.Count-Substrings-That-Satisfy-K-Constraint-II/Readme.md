### 3261.Count-Substrings-That-Satisfy-K-Constraint-II

假设以i作为左边界，那么我们容易得到最远的右边界j，使得[i:j]是最长的valid substring；并且以其中的任何一点作为右边界，都是valid substring. 然后发现，如果将左边界i往右移动一位，那么最远的右边界位置j不然是单调向右移动的。所以我们可以用双指针的方法，求得所有的len[i]，表示以i作为左边界，那么我们得到最远的valid substring的右边界。

那么对于一个query而言，如何求[l,r]内所有的valid substring呢？考虑到Q的数量很大，我们很容易想到线段树，希望能用log的时间来解决一个query（计算一个区间内的substring之和）。但是一个valid sbustring是需要用两个端点来表示的，这似乎和线段树的应用有些不同。于是我们想到，能否在线段树里用一个点来表示一个substring？于是我们可以尝试将所有的valid substring只用其左端点来表示。那么线段树就可以很方便地求出所有左端点落入[l,r]内valid substring的个数。

但是这里就有个问题，[l,r]内所有的valid substring，并不等同于左端点落入[l,r]内valid substring。
