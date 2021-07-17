### 795.Number-of-Subarrays-with-Bounded-Maximum

#### 解法1：
我们枚举每个数值范围在[L,R]之间的数nums[i]，考虑如果它是subarray的最大值，那么这样的subarray有几个？很显然，我们只需要找到```j = prevGreater[i]```以及```k = nextGreater[i]```，那么这样的subarray的左边界可以到达j+1，右边界可以到达k-1，那么这样的subarray的个数就是```(i-j)*(k-i)```. 

这样的做法需要three pass，并且要注意这种情况:[8,5,5,5,5,8]，且[L,R]=[4,6]，那么每个5作为最大值的时候可能会把区间[5,5,5,5]考虑进去，造成重复计数。一个解决方法就是我们规定，如果一个区间内如果有多个最大值，我们约定最靠左边的那个是“真正的”最大值。因此j的计算应该改为```j = previGreaterOrEqual[i]```.

#### 解法2：
首先，我们需要观察到，这个数组被大于R的元素分割成了若干段。任何subarray不能包含大于R的元素。所以我们只需要在每个片段里考察。

假设这个片段的起点位置是start。本题枚举的技巧是：如果A[i]作为subarray的最后一个，那么这个subarray的第一个元素可以取在哪里？显然我们只要找左边最接近的、数值落在[L,R]区间的那个位置lastLR，那么只要subarray包含它，就是一个合法的subarray。所以以A[i]为结尾的合法subarray的个数就是```lastLR-start+1```.

最终的答案就是遍历A[i]，累加以其为结尾的subarray的个数。
