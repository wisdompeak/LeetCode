### 356.Line-Reflection

首先，需要确定这些点关于x的对称中心位置，即镜面位置。注意到重复点在本题只算一个点，所以需要借助Set排除重复的干扰。   
根据数学关系，易知：x1,x2,...,x_n的对称中心，应该等于(x1+x2+...+x_n)/N
```cpp
        unordered_set<int>Set;
        for (int i=0; i<N; i++)        
            Set.insert(points[i].first);               
        float x0=0;
        for (auto a:Set)
            x0+=a;
        x0=x0/Set.size();
```
然后要判断这些点关于x=x0镜面对称，需要先保证对称点都在同一个y坐标上。所以利用Map来对这些点关于y的位置进行分类。
```cpp
        unordered_map<int,set<int>>Map;
        for (int i=0; i<N; i++)
        {
            Map[points[i].second].insert(points[i].first);
        }
```
对于每个y位置，都有一个集合包括了若干个不重复的x位置，我们需要保证它们两两关于x0对称。利用了set的自动排序特点，我们可以用双指针从两边往中间夹逼。
```cpp
        for (auto a:Map)
        {
            vector<int>q(a.second.begin(),a.second.end()); //因为set是有序的，直接导入一个数组中。
            int i=0;
            int j=q.size()-1;
            while (i<=j)
            {
                if (q[i]+q[j]!=x0*2)  // 关于x0对称的判据
                    return false;
                i++;
                j--;
            }
        }
```        


[Leetcode Link](https://leetcode.com/problems/line-reflection)