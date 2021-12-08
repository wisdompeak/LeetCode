### 2076.Process-Restricted-Friend-Requests

我们想判断x和y是否能成为朋友，取决于x所在的家族X、y所在的家族Y，不能有任何一对是敌人。换句话说，如果家族X、家族Y中有存在任何一对是restriction，那么x和y就不能归并到一起。

显然，我们不可能穷举X家族、Y家族的配对。但是翻过来，我们可以穷举所有的restriction，查看每对敌人的双方是否分别存在这两个家族之中。这样，时间复杂度就是request的数目乘以restriction的数目，恰好符合题意。
