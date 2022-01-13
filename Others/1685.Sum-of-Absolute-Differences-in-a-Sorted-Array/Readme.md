### 1685.Sum-of-Absolute-Differences-in-a-Sorted-Array

假设我们已知“所有元素与nums[i-1]的差的绝对值的和是sum”，那么我们可以推论出“所有元素与nums[i]的差的绝对值的和”。见下图的分析。我们称被比较的那个数是“目标值”（即上一个回合是nums[i-1]，这一个回合是nums[i]）.
```
X X X X, i-1, i, X X X X 
```
随着目标值的移动，原先目标值左边的元素（包括自身，即nums[0:i-1]）与新目标值的差值全部都增加了```nums[i]-nums[i-1]```，总共增加了```(nums[i]-nums[i-1])*i```. 随着目标值的移动，原先目标值右边的元素（即nums[i:n-1]）与新目标值的差值全部都减少了```nums[i]-nums[i-1]```，总共减少了```(nums[i]-nums[i-1])*(n-i)```. 

可见我们有递推关系```sum[i] = sum[i-1]+(nums[i]-nums[i-1])*i-(nums[i]-nums[i-1])*(n-i)```.
