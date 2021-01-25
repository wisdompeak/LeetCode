### 1734.Decode-XORed-Permutation

我们知道，XOR的最常用的一个性质就是x^x=0，我们需要尽量使用这个性质。但是我们发现如果把encode里面的元素全部XOR起来，大多数元素都会被消除，得到的只是头尾值```nums[0]^nums[n-1]```.

这时候我们注意到题目中说n是个奇数，这个条件很奇怪。仔细分析了一下，发现我们如果间隔着取encode里面的元素再XOR起来，就得到```nohead = nums[1]^numx[2]^...^nums[n-1]```，只缺少了nums[0]而已.这时候我们果断想到全局的XOR Sum其实是已知的（因为题目说的是1到n的permutation）。将nohead与XORSum再亦或一下，就得到了nums[0]。于是nums[1]就可以从encode[0]^nums[0]得到，其余的nums[i]也就迎刃而解。
