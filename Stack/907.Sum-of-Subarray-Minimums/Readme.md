### 907.Sum-of-Subarray-Minimums

我们考虑对于每个元素A[i]，如果以它作为最小值，那么这样的subarray能有多大？显然，我们找在i之前的第一个比A[i]小的数，比如说j；再找i之后第一个比A[i]小的数，比如说k，那么从[j+1,k-1]就是最大的subarray。并且，以任意[j+1,i]为左边界、任意[i,k-1]为右边界的subarray，也都是以A[i]为最小值。所以，以A[i]为最小的subarray的个数就有(i-j)*(k-i)个。

所以，本题就演变成了求每个元素的next smaller element，以及previous smaller element.这些都是用单调栈算法的经典用法。

但是需要特别注意的是，如果一个subarray里面有多个相同的最小值，那么这个subarray的最小值到底归属于谁呢？为了避免重复计算，我们需要做额外规定以做区分。比如认为如果有若干个相同的数，则最左边的那个才是最小值。这样的话，类似[3,4,4,3,4,4,3]这样的subarray，只会在考察第一个3的时候被计入，而在考察其他的3的时候不会被计入。

所以本题确切的说，是求每个元素的next smaller element，以及previous smaller or equal element. 另外，特别注意：如果一个数没有next smaller element，那么意味着它的左边界是可以到n；如果一个数没有prev smaller/equal element，那么意味着它的左边界是可以到-1.

Update: 事实上，`next smaller element`和`previous smaller or equal element`可以one-pass同时实现。
```cpp
  for (int i=0; i<n; i++)
  {
      while (!Stack.empty() && arr[Stack.top()] > arr[i])
      {
          nextSmaller[Stack.top()] = i;
          Stack.pop();
      }

      if (!Stack.empty())
          prevSmaller[i] = Stack.top();
      Stack.push(i);
  }
```


[Leetcode Link](https://leetcode.com/problems/sum-of-subarray-minimums)
