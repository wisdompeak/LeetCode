### 223.Rectangle-Area

整体而言这是一个容斥原理的应用。```A并B = A + B - A交B```

其中“A交B”的面积计算，通过确定相交区域的左下角和右上角来得到。
```
x_left_bottom = max(x1_left_bottom, x2_left_bottom)
y_left_bottom = max(y1_left_bottom, y2_left_bottom)
x_right_top = min(x1_right_top, x2_right_top)
y_right_top = min(y1_right_top, y2_right_top)
```

特别注意要检查 ```x_left_bottom < x_right_top```和 ```y_left_bottom < y_right_top```，才能说明有真正意义的相交矩形。


[Leetcode Link](https://leetcode.com/problems/rectangle-area)