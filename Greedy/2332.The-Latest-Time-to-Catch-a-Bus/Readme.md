### 2332.The-Latest-Time-to-Catch-a-Bus

我们想象，如果“我”不存在，只有已知的那些passengers，那么我们应该很容易这道哪些乘客上哪些车。而现在想做的基本方针，是看看能不能比某个乘客早一秒到达，这样就把他的位置挤占了（当然还有其他约束条件），从而搭上这班车。

我们先来写代码，看看当前这些passengers与车的匹配。这是一个明显的双指针
```cpp
    int j = 0;        
    for (int i=0; i<buses.size(); i++)
    {
        int cap = capacity;        
        while (j<m && passengers[j]<=buses[i] && cap>0)
        {
            // passengers[j]可以乘坐buses[i]
            cap--;
            j++;
        }
    }
```

那么我们就考察，如果我们比passengers[j]早到一秒钟，能不能挤掉它的位置坐上buses[i]呢？显然，只要```passengers[j]-1!=passengers[j-1]```，我们就可以实现。

那么还有没有其他不需要挤占其他乘客的可能性呢？其实buses[i]不一定都坐满了。如果最后一个上车的乘客与班车开动的时刻之间有空隙，那么我们就直接在buses[i]时刻上车即可。

依据上面的算法，我们遍历每辆车，考察该车的每个乘客能否被挤占，或者是否可以卡点上车，就可以确定自己上车的时间。
