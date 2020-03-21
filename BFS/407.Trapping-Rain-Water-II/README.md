# leetcode-407-Trapping-Rain-Water-II
注意此题和一维的版本不一样，无法使用DP的思想。

### 此题的解法思想   
假想一个海平面逐渐上升。维护一个海岸线的队列（初始值就是矩阵外围的一圈），每次海平面上升后冲过最矮的堤坝，把内陆的低洼淹掉；形成新的海岸线（加入新元素入列）。重复直至所有元素都被淹没。  

### 海岸线的数据结构   
因为希望海岸线能自动排序，队首永远是最小的，所有得采用priority_queue。默认的优先队列是大顶堆，所以必须手动设计小顶堆。    
```cpp    
priority_queue< classType, vector<calssType>, greater<classType>> SeaShore
```   
这里的classType是一个pair类型 ```pair<int,int>```，第一个装数值，第二个装坐标（ixN+j)。STL自动以第一个的权重进行排序。  
或者手动设计cmp比较函数：
```cpp    
struct cmp
{
  bool operator()(pair<int,int>a,pair<int,int>b)
  { return a.first>b.first;)
};
priority_queue< pair<int,int>, vector<pair<int,int>>, cmp> SeaShore
```   

### 算法   
每次从SeaShore里弹出一个最矮的堤坝，标记此时的海平面level，以此开始内部的BFS，定义为flood吧。将所有为访问过的、低于level的元素加入Q队列并计算存水量；将所有不低于level的元素加入SeaShore队列，表明新的海岸线生成。搜索到flood空为止。  

注意无论是加入flood队列还是SeaShore队列，都要标记已经访问过，以后不需要再加入任何队列。


[Leetcode Link](https://leetcode.com/problems/trapping-rain-water-ii)