### 2166.Design-Bitset

本题不要试图用C++自带的bitset做。C++的bitset在初始化时不能自定义空间大小，如果开满了N=1e5，那么就会TLE。

本题设立两个变量分别是flip[i]和totalFlip。前者表示第i个元素被单独翻转了几次，后者表示所有元素被翻转了几次。那么任意元素在任意时刻的最终状态就是```(flip[i]+totalFlip)%2```.
