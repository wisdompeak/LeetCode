### 2958.Length-of-Longest-Subarray-With-at-Most-K-Frequency

本题就是维护一个滑窗，使得滑窗内的任何元素的频次不能超过K。如果满足条件，那么就移动右边界；如果不满足，那就移动左边界。
