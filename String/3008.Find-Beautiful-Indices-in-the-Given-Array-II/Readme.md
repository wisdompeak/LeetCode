### 3008.Find-Beautiful-Indices-in-the-Given-Array-II

很显然，我们只需要找出a在s中出现的所有位置pos1，以及b在s中出现的所有位置pos2。这个用KMP的模板即可。

对于pos1中的每个位置i，我们只需要查找`i-k`在pos2里的位置（lower_bound，第一个大于等于该数的迭代器），以及`i+k`在pos2里的位置（upper_bound，第一个大于该数的迭代器），两个位置之差即代表有多少pos2的元素位于[i-k, i+k]之间。
