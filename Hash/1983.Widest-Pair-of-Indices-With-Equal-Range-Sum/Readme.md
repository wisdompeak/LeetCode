### 1983.Widest-Pair-of-Indices-With-Equal-Range-Sum

令pre1表示nums1的前缀和数组，pre2表示nums2的前缀和数组。本题即求跨度最大的{i,j}使得
```
pre1[j]-pre1[i] = pre2[j]-pre2[i]
```
稍微移项变换
```
pre1[j]-pre2[j] = pre1[i]-pre2[i]
```
令diff数组表示pre1-pre2之差，那么本题的本质就是在diff数组里找跨度最大的{i,j}使得
```
dfff[i] = diff[j]
```
