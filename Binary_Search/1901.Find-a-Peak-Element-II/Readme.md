### 1901.Find-a-Peak-Element-II

本题的思路非常巧妙。我们搜一行max_mid，查看该行的最大值max_mid. 同时查看该行上一行的最大值max_upper，该行下一行的最大值max_lower。如果max_mid是三者中的最大，那么根据大小比较的传递性，max_mid肯定比它的上一格大，因为max_mid大于upper_mid，而upper_mid是上一行中的最大值。同理，max_mid也比它的下一个大。所以max_mid一定是一个峰值。

如果max_upper是三者中的最大，那么我们就将峰值所在行的搜索范围调整为[low, mid-1];反之，如果max_lower是三者中的最大，那么我们就将峰值所在行的搜索范围调整为[mid+1,high].

本题一定有解，所以当```while (low<high)```退出时，low所在行的最大值就一定是峰值。
