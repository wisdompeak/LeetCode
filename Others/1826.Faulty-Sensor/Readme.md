### 1826.Faulty-Sensor

我们逐位比较，先定位第一次出现不同元素的位置i。如果不存在i，或者i在最后一个位置，那么就无法判断。

接下来比较sensor1[i:n-2]是否和sensor2[i+1:n-1]完全对应。是的话，就有可能sensor1丢失了数据，我们标记为flag1为true。同理，比较sensor2[i:n-2]是否和sensor1[i+1:n-1]完全对应。是的话，就有可能sensor2丢失了数据，我们标记为flag2为true。

注意如果flag1和flag2都为true或者flase时，为无法判断。否则输出flag1或者flag2中为true的那个。
