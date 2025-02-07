### 3428.Maximum-and-Minimum-Sums-of-at-Most-Size-K-Subsequences

入手的思路很常规。我们不会枚举所有的subsequence然后查找它的最大值（或最小值）。反过来，我们会对每个元素考察，如果它是一个subsequence里的最大值（或最小值），那么这个subsequenec有多少个？

显然，对于任意的nums[i]，我们只需要在其他比它小的元素里找kk个即可（其中kk<=k-1）。如果有m个比它小的元素，那么以nums[i]为最大值的subsequence就有comb(m,kk)个。考虑到m不超过1e5，kk不超过70，我们可以提前将所有的comb(m,kk)都计算好。

此题需要注意的是，数值相同的nums可能有多个。也就是说，如果一个subsequence里同时有nums[i]和nums[j]都是最大值，那么我们不能将这个subsequence重复分给这两个数，只能挑一个来计算最大值。因此我们可以约定，比如说，只有最后一个出现的最大元素才是最大值。

更方便的做法是，因为本题的subsequence只看最大值，并不在意元素之间相对的顺序。所以我们可以直接将nums排序。因为排序前的任何一个subsequence，必然一一对应排序后的某个subsequence。对于排序后的nums，当我们认定nums[i]是最大值时，符合条件的subsequence的其他元素就必然在nums[:i-1]里任选即可。这样的组合就有`sum{comb(i, kk)}, where kk=0,1,..,k-1`.

