### 381.Insert-Delete-GetRandom-O-1-Duplicates-allowed

此题是380的follow up。基本思路仍然是用Map来查找元素，用array来新增元素。

显然对于val->pos的映射应该构建 unordered_map<int,unordered_set<int>>val2pos, 以存储val对应的所有在数组中的（若干个）位置。

在Delete(val)过程中，腾出的位置要用```val2 = array.back()```来替换，相应地```val2pos[val2]```也要更新，即删除val2原来的位置（也就是nums的末尾），添加val的位置。

完整的元素删除代码：
```cpp
    bool remove(int val) 
    {
        int flag = val2pos.find(val)!=val2pos.end();
        if (flag==false) return false;
        
        int pos = *(val2pos[val].begin());
        int val2 = nums.back();
        
        if (val2==val)
        {
            nums.pop_back();
        }
        else
        {
            int pos2 = nums.size()-1;
            nums[pos] = val2;
            nums.pop_back();
            val2pos[val2].erase(pos2);
            val2pos[val2].insert(pos);
        }
        
        val2pos[val].erase(pos);
        if (val2pos[val].size()==0)
            val2pos.erase(val);
        
        return flag;
        
    }
```
特别注意：如果val就是nums末尾的元素（即```val==val2```)，那么直接弹出nums的末尾元素即可。这种情况不应该和其他gengeral的情况混淆在一起处理，容易出错。
