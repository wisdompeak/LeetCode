### 2999.Count-the-Number-of-Powerful-Integers

首先，对于区间内的计数，常用的技巧就是转化为`helper(to_string(finish), limit, s) - helper(to_string(start-1), limit, s)`，其中`helper(string a, int limit, string s)`表示在[1:a]区间内有多少符合条件的数（即每个digit不超过limit且后缀为s）。

接下来写helper函数。令上限a的长度为d，那么我们计数的时候只需要逐位填充、循环d次即可。对于第k位而言，分两种情况：
1. 如果填充的前k-1位小于a同样长度的前缀，那么第k位可以任意填充0 ~ limit都不会超过上限a。甚至从第k+1位起，直至固定的后缀s之前，总共有`d = a.size()-s.size()-k`位待填充的数字，都可以任意填充为0~limit。故直接返回计数结果：`pow(1+limit, d)`.
2. 如果填充的前k-1位等于a同样长度的前缀，那么第k位可以填充为0 ~ min(limit, a[k])。确定之后，接下来递归处理下一位即可。注意，如果填充为a[k]的话，需要告知递归函数“已构造的前缀继续与a相同”，否则告知递归函数“已构造的前缀小于a”。这样下一轮递归函数知道选择哪一个分支。
