### 3604.Minimum-Time-to-Reach-Destination-in-Directed-Graph

常规的Dijkstra的模版题。本题优先队里的元素需要定义状态
```cpp
struct state {
    int node, time;
    bool operator<(state const& o) const {
        return time > o.time;
    }
};
```
对于出队列的一个状态{node,time}，我们可知到达node的最短时间就是time。然后我们检查它周围的路径{v,start,end}。如果time<start，那么我们就把{v,start+1}加入优先队列。如果time在[start,end]时段内，那么我们就把{v,time+1}加入优先队列。
