### 1714.Sum-Of-Special-Evenly-Spaced-Elements-In-Array

https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/discuss/1008468/

#### solution 1 
Same idea as https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/discuss/1006993/ Just implemented it in C++.

Rough explanation:

Let query = [s,d]

When d >= sqrt(n)，just brute loop the numbers we want to add. It takes at most o(sqrt(N)).

When d < sqrt(n), would be better to prepare the prefix sum array as ```presum[d][offset]```，where  ```offset = s%d```.  ```presum[d][offset]``` is the summation of ```nums[offset] + nums[offset+d] + nums[offset+d*2] + ... ``` Then the result of this query is simply ```presum[d][offset][(n-1-offset)/d] - presum[d][offset][(s-1-offset)/d] ``` The pre-computation for one query takes ```o(N/d)``` which is around ```o(sqrt(N))```, but it can be stored for reuse (if multiple queries share the same d and offset). 

#### solution 2 
Same idea as https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/discuss/1007086/ Just implemented it in C++.

When d >= sqrt(n)，just brute loop the numbers we want to add. It takes at most o(sqrt(N)).

When d < sqrt(n), would be better to prepare the suffix sum array as ```sufsum[d][i]```.  ```sufsum[d][i]``` is the summation of ```nums[i] + nums[i+d] + nums[i+d*2] + ... ``` Then the result of this query is simply ```sufsum[d][s]``` The pre-computation for one query always takes ```o(N)```, but it can be stored for reuse (if multiple queries share the same d). 

Both solutions are slow in C++ (beat 5%).
