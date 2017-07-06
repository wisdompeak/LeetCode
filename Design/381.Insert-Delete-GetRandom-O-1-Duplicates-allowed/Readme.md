### 381.Insert-Delete-GetRandom-O-1-Duplicates-allowed

此题是380的follow up。基本思路仍然是用Map来查找元素，用array来新增元素。

显然对于val->pos的映射应该构建 unordered_map<int,vector<int>>Map 以存储val对应的所有在数组中的位置。

在Delete(val)过程中，腾出的位置要用array.back()来替换，相应地Map[array.back()]也要更新。注意要找Map[array.back()]中等于array.size()-1的那个位置替换为val的pos，而那个位置并不必然就是Map[array.back()].back()。    

完整的元素删除代码：
```cpp
    bool remove(int val) 
    {
        if (Map.find(val)==Map.end())
            return false;
        else
        {
            int pos = Map[val].back();
            array[pos]=array.back();
            for (int i=0; i<Map[array.back()].size(); i++)
            {
                if (Map[array.back()][i]==array.size()-1)
                {
                    Map[array.back()][i] = pos;
                    break;
                }
            }
            array.pop_back();
            Map[val].pop_back();
            if (Map[val].size()==0)
                Map.erase(val);
            return true;
        }
    }
```
上述代码中最容易出错的地方在于，if (Map[val].size()==0) Map.erase(val)这句话只能放在最后操作。这是因为val可能恰恰就是array.back()，过早地删去了val这个key，会导致后续Map[array.back()]非法，即 runtime error.

一个比较保险的方式是，弃用if (Map.find(val)==Map.end())，使用 if (Map.count(val)==0).
