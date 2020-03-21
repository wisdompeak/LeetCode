### 990.Satisfiability-of-Equality-Equations

容易想到如果遇到```a==b```，那么a和b可以通过Union Find聚为一类。

如果遇到```a!=b```，那么我们会检查a和b是否已经聚成了一类，是的话就说明引入了矛盾，返回false；如果不是的话，目前但前暂时没有导出矛盾。但问题是，我们如何保证之后再遇到```a==b```时能记住之前的```a!=b```呢？

解决方法很简单，就是先考察所有的等式，将所有的能聚类的元素都聚起来。然后再考察所有的不等式，考察是否有与之前那些等式相矛盾的地方。没有任何矛盾的话就返回true。


[Leetcode Link](https://leetcode.com/problems/satisfiability-of-equality-equations)