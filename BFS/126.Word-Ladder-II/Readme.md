### 126.Word-Ladder-II

这是一道考点比较综合全面的ＢＦＳ题．需要注意的几点是：

１．提前处理这个wordList，将其放入一个wordSet中．并且对于每个单词，我们都提前计算好它的next可能是哪些．

２．看清题意，这个wordSet必须包含endWord，否则直接返回空．另外，记得把beginWord也要放进去，否则就不会生成它的next.

3.题目要求所有的最短路径．这就说明不仅仅是搜到endWord就停止，必须把同一个层级的都搜索完．所以建议用如下的trick
```
while (!q.empty())
{
  int len = q.size();
  for (int k=0; k<len; k++)
  {
    ...
    if (endWord) flag=1;
  }
  if (flag==1) break;
}
```
要保证一个for循环完整地执行完．

4.要找到回溯的路径，就需要保存所有单词的prev．因为可能有多条最短路径都经过str，那么str的ｐｒｅｖ需要是一个集合．最后回溯的方法用DFS.


[Leetcode Link](https://leetcode.com/problems/word-ladder-ii)