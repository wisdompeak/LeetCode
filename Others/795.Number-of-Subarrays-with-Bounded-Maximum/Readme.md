### 795.Number-of-Subarrays-with-Bounded-Maximum

首先，我们需要观察到，这个数组被大于R的元素分割成了若干段。任何subarray不能包含大于R的元素。所以我们只需要在每个片段里考察。

假设这个片段的起点位置是start。本题枚举的技巧是：如果A[i]作为subarray的最后一个，那么这个subarray的第一个元素可以取在哪里？显然我们只要找左边最接近的、数值落在[L,R]区间的那个位置lastLR，那么只要subarray包含它，就是一个合法的subarray。所以以A[i]为结尾的合法subarray的个数就是```lastLR-start+1```.

最终的答案就是遍历A[i]，累加以其为结尾的subarray的个数。
