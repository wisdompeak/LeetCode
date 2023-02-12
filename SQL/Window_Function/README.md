### 窗口函数

#### 利用rank()求分区里的最大值
在原表里插入rank存为新表。再在新表里选择rank=1的行。
```sql
with temp as 
(
    select *, rank() over (partition by student_id order by grade desc, course_id) as rnk
    from Enrollments
)
select student_id, course_id, grade
from temp
where rnk = 1
```

#### 利用count()求分区里的行数
```sql
select *, count(activity) over (partition by username) as cnt
```

#### first_value() / last_value() 取最小值/最大值
```sql
select first_value(device_id) over (partition by player_id order by event_date) as device_id
```

#### 配合distinct实现group by的效果
```sql
select distinct player_id, first_value(device_id) over (partition by player_id order by event_date) as device_id
```
这样本质上等同于`group by player_id`

#### 利用sum()求分区间的累积前缀
按天数累积
```sql
SELECT gender, day, SUM(score_points) OVER(PARTITION BY gender ORDER BY day) AS total
FROM Scores
```
LC 534, 

#### 各种rank函数
rank()：正常排名，允许并列。两个第一名的话，则没有第二名。        
dense_rank()：正常排名，允许并列。两个第一名的话，依然有第二名。      
row_number(); 排名不允许有并列。     

#### 优先操作累积函数，再操作窗口函数
在下面的代码里，优先考虑`group by Orders.product_id, customer_id`，group之后每一行就可以定义count(Orders.product_id)，再依据customer_id的分区分别进行rank
```sql
select Orders.product_id, product_name, customer_id, 
    rank() over (partition by customer_id order by count(Orders.product_id) desc) as rnk
from Orders
left join Products on Orders.product_id = Products.product_id
group by Orders.product_id, customer_id  
```

#### 窗口函数内排序后用lead求某列的下一行
对于每个user_id，按时间先后排序visit_data。用`lead(visit_date, 1, '2021-01-01')`可以求出此时表里visit_date的下一行，其中第三个参数表示没有下一行时的默认值。
```sql
select lead(visit_date, 1, '2021-01-01') over (partition by user_id order by visit_date) as next
from UserVisits
```
