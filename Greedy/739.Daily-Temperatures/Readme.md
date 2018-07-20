### 739.Daily-Temperatures

此题可以从后往前考虑．对于results[i]，我们考察其右边的那个元素，即```results[j],where j=i+1```. 

当temp[j]<=temp[i],我们将指针跳转j+=results[j]，这样就可以加快搜索的效率．这样直到找到一个temp[j]>temp[i]即为找到结果；或者直到发现results[j]==0时说明再也找不下去了．
