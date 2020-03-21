### 380.Insert-Delete-GetRandom-O(1)

插入是o(1)操作的，只有数组的push_back，否则用链表至少o(logn)，还得保证是有序的； 

同理，删除是o(1)操作的，只有数组的pop_back，否则至少o(logn)；  

查找是o(1)操作的只有哈希表。

因此考虑到用Map和数组。Map记录元素和数组位置之间的对应关系。

特别注意remove所需要的几个操作，把val和数组尾的元素对调：
```cpp
        if (Map.find(val)==Map.end())
            return false;
        else
        {
            q[Map[val]] = q.back();  //  将数组尾元素放在val的位置上
            Map[q.back()] = Map[val];  // 修改数组尾元素的新位置映射
            q.pop_back();  // 数组丢弃尾元素
            Map.erase(val);  // 映射丢弃原来的val
            return true;
        }
```
特别需要小心的细节就是，Map.erase(val)和Map[q.back()]=pos的操作顺序，前者必须放在最后。否则若 val=q.back()时，val并不能真正从Map里删除，因为Map[q.back()]=pos又会把其加回去。

另外，随机生成整形随机数的函数 rand(); 如果需要0~N-1范围内的随机数，就是 rand() % N


[Leetcode Link](https://leetcode.com/problems/insert-delete-getrandom-o-1)