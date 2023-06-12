### 2730.Find-the-Longest-Semi-Repetitive-Substring

典型的双指针滑窗。我们试图维护一个合法的`[i,j)`的滑窗。

基本的算法是，固定一个i的位置，向右滑动右边界j，直至发现加入j后会使得[i:j]范围内“consecutive pair”的count达到2，此时停止j的移动。然后我们再开始下一个回合（i指向右边的位置）前，注意count是否需要因为i的移动而减一。
