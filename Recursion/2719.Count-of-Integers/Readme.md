### 2719.Count-of-Integers

求介于两个范围[low, high]之间的、符合条件的元素个数，一个非常常见的套路，就是只写一个求不高于某上界、符合条件的元素个数`NoGreaterThan`.这样答案就是`NoGreaterThan(high)-NoGreaterThan(low-1)`.

本题有两个不同类型的范围限制，数值大小的范围和digitsum的范围。我们用同样的套路，写函数`NoGreaterThan(string num, int max_sum)`，求数值上不超过num，digitSum不超过max_sum的元素个数，这样最终答案就是
```
return (NoGreaterThan(num2, max_sum)-NoGreaterThan(num2, min_sum-1)) 
          - (NoGreaterThan(num1-1, max_sum)-NoGreaterThan(num1-1, min_sum-1));
```

在编写`NoGreaterThan`的时候，我们递归考察num的每个位置，尝试可以填写哪些digits。用记忆化来避免重复的函数调用。

其中一个比较重要的逻辑就是，如果我们给前i位设置的digits比num对应前缀要小，那么第i位上我们可以任意设置0~9都可以满足要求（即不超过num）。反之，如果给前i位设置的digits与num的对应前缀完全吻合，那么在第i位上的设置就不能超过num[i]（否则就超过了num）。所以递归的时候我们需要有一个bool量的标记，表示在处理当前位i之前，我们是否设置了完全与num前缀相同的digits。

此外，对于cpp而言，我们比较难直接得到num-1的字符串形式。技巧是我们将num1单独处理即可。
