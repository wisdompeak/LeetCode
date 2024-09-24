### 3261.Count-Substrings-That-Satisfy-K-Constraint-II

假设以i作为左边界，那么我们容易得到最远的右边界j，使得[i:j]是最长的valid substring；并且以其中的任何一点作为右边界，都是valid substring. 然后发现，如果将左边界i往右移动一位，那么最远的右边界位置j必然是单调向右移动的。所以我们可以用双指针的方法，求得所有的len[i]，表示以i作为左边界，那么我们得到最远的valid substring的右边界。

那么对于一个query而言，如何求[l,r]内所有的valid substring呢？考虑到Q的数量很大，我们很容易想到线段树，希望能用log的时间来解决一个query（计算一个区间内的substring之和）。但是一个valid sbustring是需要用两个端点来表示的，这似乎和线段树的应用有些不同。于是我们想到，能否在线段树里用一个点来表示一个substring？于是我们可以尝试将所有的valid substring只用其右端点来表示。举个例子，对于以i为左端点的valid subtring，根据其右端点的位置，我们在i,i+1,i+2,...,len[i]都可以记录+1；也就是说，在线段树上我们可以对[i,len[i]]这段区间整体都加1. 此外，线段树就可以很方便地query所有右端点落入[l,r]内valid substring的个数。

但是这里就有个问题，[l,r]内的valid substring，并不等同于右端点落入[l,r]内valid substring。对于后者而言，有些substring的左端点在l的左边，这是需要排除掉的。我们该如何去掉那些左端点在l左边的那些substring呢？在线段树的操作里，似乎并没有什么好办法，但是有一个巧妙的策略：那就是不把“那些左端点位于l左边的那些substring”收录进线段树。这就提示我们可以将queries按照左端点倒序排列依次处理。对于[l,r]这个query而言，我们（只）收录进所有左端点大于等于l的那些substring。此时在线段树内查询[l,r]的区间和，就代表了所有右端点在[l,r]范围内的valid substring，同时这些string的左端点都不会小于l。
