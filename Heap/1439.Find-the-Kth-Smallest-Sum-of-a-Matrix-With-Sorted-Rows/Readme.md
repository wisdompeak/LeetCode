### 1439.Find-the-Kth-Smallest-Sum-of-a-Matrix-With-Sorted-Rows

我们注意到，虽然array的组合有m^n个，但本题中的K不超过200.这说明我们是可以暴力找到第K大sum的array的！

我们的初始状态是sum最小的array，也就是每行取第一个元素。然后基于这个array，分别将每行的元素替换为该行的下一个，这样就可以扩展出m个array...将所有拓展出的array放在一个PQ里，然后每次弹出的是sum最小的array，继续拓展...可见，此题本质上是就N sorted list的归并排序。

注意的是，我们在本题采用的数据结构是set而不是PQ，是因为考虑到去重的问题。要警惕某种array的组合，可能会由不同的array拓展而来，我们不能重复加入进PQ，必须做visited标记。如果用有序的set可以同时起到去重的作用，一举两得。
