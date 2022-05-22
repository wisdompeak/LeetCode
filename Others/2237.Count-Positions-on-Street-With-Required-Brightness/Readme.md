### 2237.Count-Positions-on-Street-With-Required-Brightness

扫描线算法的模板题。假设某盏灯的覆盖范围是[a,b]，那么我们就设置差分数组diff[a]+=1和diff[b+1]-=1. 注意因为在b位置处我们是希望计入被灯光覆盖，所以-1的差分应该写在b+1这个地方。
