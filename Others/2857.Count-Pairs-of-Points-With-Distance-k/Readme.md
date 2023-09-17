### 2857.Count-Pairs-of-Points-With-Distance-k

本题的关键点在于k<=100. 因为`(x1 XOR x2) + (y1 XOR y2)`的两个分量都是非负数，所以我们可以穷举`k=a+b`的拆解。已知a,b,通过枚举(x1,y1)，我们就可以知道对应的x2,y2. 只需要用Hash查看(x2,y2)是否存在即可。
