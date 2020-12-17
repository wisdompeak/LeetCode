### 1418.Display-Table-of-Food-Orders-in-a-Restaurant

本题有很多数据结构的设计方法，但是彼此之间的时间复杂度差别很大。

比较快的方法是：设计```map<int, unordered_map<string, int>>table2Order```，用来记录每个桌号、每道food被点单的次数。其中桌号已经满足了升序排列。这其实已经和最终的表格样式很接近了。我们还需要知道每道food的点单次数应该填在哪个列。故我们把所有food name经过排序后，就可以得到每道food所对应的Column编号的映射。
