### 1167.Minimum-Cost-to-Connect-Sticks

因为每根棍子的总cost取决于它参加了几次合并。很显然，我们会优先选择最轻的两根sticks进行合并，将重的stick放到最后再合并。

每次将新生成的stick放入群体中，再继续挑选两根最轻的进行合并。直至最终把所有棍子合并完成。
