### 732.My-Calendar-III

此题有奇思妙解. 

我们设计一个顺序的multiset<pair<int,int>>Set,每次调用我们就往里面放置{start,1}和{end,-1}.然后遍历这个集合,按照从小到大的顺序更新一个计数器,遇到1就加一,遇到-1就减一.

奇妙的就是,你这样可以实时得到的,就是当前k booking的状态.遍历完之后这个计数器的历史最大值就是答案.


[Leetcode Link](https://leetcode.com/problems/my-calendar-iii)