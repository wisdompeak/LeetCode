### 883.Projection-Area-of-3D-Shapes

从题目给出的示意图就可以看出，从某一个方向看过去的投影高度，完全取决于这个方向上能看到的最高的那根柱子的高度。比如对于x=i方向上，投影到y-z平面上的高度其实就是```max{grid[i][j]} for j=0,1,2,...```。所以对于y-z平面上的总投影面积，就是把所有的```max{grid[i]}```加起来就行。

对于x-z平面上的总投影也是如此处理。计算每个col[j]，表示第j列上的的最大值。再把所有col[j]相加。

对于x-y平面上的总投影，处理起来更为简单，就是计算grid[i][j]有多少个非零元素即可。


[Leetcode Link](https://leetcode.com/problems/projection-area-of-3d-shapes)