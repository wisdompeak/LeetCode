### 2551.Put-Marbles-in-Bags

显然，无论怎么分组，weights[0]和weights[n-1]是必然会计入score。接下来我们需要在n个元素中间插入k-1块隔板。每块隔板引入的score就是隔板两边的相邻元素weights之和。显然要使score最大，我们只需要选取最大的k-1个“相邻元素weight之和”即可。同理，要使score最小，我们只需要选取最小的k-1个“相邻元素weight之和”即可。

所以本题只需要将n-1个`weights[i]+weights[i+1]`排序即可。取最大的k-1个元素之和，减去最小的k-1个元素之和。
