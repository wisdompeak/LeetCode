### 2397.Maximum-Rows-Covered-by-Columns

考虑到总的列数不超过12，枚举所有的列的选择都是可行的。对于一种固定的列的组合，我们记成二进制数state，先排除掉那些bit 1的个数不等于cols的。然后我们只需要查看每一行对应的二进制数row是否是state的子集即可，即`(state&row) == row`. 我们最后选择一个能cover最多row的state。

此外，我们可以用gosper's hack来提高效率，只枚举那些bit 1的个数等于cols的state。
