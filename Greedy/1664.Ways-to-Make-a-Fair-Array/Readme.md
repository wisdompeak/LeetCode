### 1664.Ways-to-Make-a-Fair-Array

本题的入手点很直观，就是遍历删除的位置i。我们可以提前计算出左边的奇数位数字之和leftOdd[i-1]、左边的偶数位数字之和leftEven[i-1]、右边的奇数位数字之和rightOdd[i+1]、右边的偶数位数字之和rightEven[i+1]。因为删除掉第i位之后，rightOdd[i+1]其实对应的数字都变成了偶数位，而rightEven[i+1]对应的数字都变成了奇数位。所以删去第i位后，我们判断全体奇数位之和是否等于偶数位之和时，判据应该是```leftEven[i-1]+rightOdd[i+1]==leftOdd[i-1]+rightEven[i+1]```.
