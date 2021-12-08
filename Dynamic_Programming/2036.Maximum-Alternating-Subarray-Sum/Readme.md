### 2036.Maximum-Alternating-Subarray-Sum

我们定义两个状态，curSum0[i]表示以元素i结尾、并且元素i本身未被符号翻转的情况下（即+nums[i]），能够得到的max subarray sum. 同理，curSum1[i]表示以元素i结尾、并且元素i本身已经被符号翻转的情况下（即-nums[i]），能够得到的max subarray sum. 

对于curSum0[i]，它两种可能。要么subarray仅包含单个元素+nums[i]。要么需要把+nums[i]和前面的subarray连起来使用：显然能与+nums[i]连在一起的，必然是curSum1[i-1]. 所以```curSum0[i] = max(nums[i], curSum1[i-1]+nums[i]```.

对于curSum1[i]，它其实只有一种可能，即需要和前面的subarray连起来使用。这是因为题目不允许subarray的开头是一个符号反转的元素。所以-nums[i]必须curSum0[i-1]连在一起. 所以```curSum1[i] = curSum0[i-1]-nums[i]```.

此外特别注意，对于边界条件，curSum1[-1]可以是0，但是curSum0[-1]必须设置为无穷小。这是因为nums[0]只能作为一个subarray的开头，它不能被符号翻转，所以```curSum1[0] = curSum0[-1]-nums[i]```没有意义。
