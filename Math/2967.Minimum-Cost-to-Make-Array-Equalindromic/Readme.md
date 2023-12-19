### 2967.Minimum-Cost-to-Make-Array-Equalindromic

根据中位数定理，Make Array Equal的最小代价就是将所有元素变成数组里的中位数（median）。本题中，我们的目标就是找到最接近中位数的回文数。可以借鉴`564. Find the Closest Palindrome`的算法，求得中位数M的next greater palindrome和next smaller palinedrome，然后选取两者较小的代价即可。

特别注意，单纯找nearest palinedrome是不对的。next greater palindrome和next smaller palinedrome相比，并不是更接近M就更好，而是与array里元素的分布有关。
