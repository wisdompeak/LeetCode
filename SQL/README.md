#### greatest, least
在同一行的多个列中选择最大/最小的一个
```sql
greatest(columnA, columnB)
least(columnA, columnB)
```

#### ifnull(A, B)
Output A if A is not null, otherwise B.


#### Union
```sql
将两段类型相同的列纵向拼接起来（组成新表）。在第一个select里可以重命名。
with temp as
(
    select user1_id as id
    from Friendship
    where user2_id = 1
    union
    select user2_id
    from Friendship
    where user1_id = 1
)
```

#### 日期类型的操作
##### between
```sql
purchase_date between Prices.start_date and Prices.end_date
```
##### left/right
选择一个date数据“2020-19-12”的左七位数字作为month的标记。
```sql
left(trans_date, 7) as month
```
##### datediff
计算两个时间之差（前者减后者）
```sql
join XXX on datediff(a.visited_on, b.visited_on) between 0 and 6
```

#### Join
##### Join Condition 可以有复杂的表达式
```sql
join UnitsSold on Prices.product_id = UnitsSold.product_id 
    and UnitsSold.purchase_date between Prices.start_date and Prices.end_date  
```    

### 临时表
#### 定义临时表
```sql
with Temp1 as
(
    select winner_id
    from Winners
), Temp2 as
(
    select player_id
    from Players
)

select
    Round((select count(*) from Winner) / (select count(*) from Players), 2) AS fraction
```
#### 取临时表的某一列
```sql
with temp as
(
    select count(x) as total
    from table
)
select name, total
from table, temp
```
#### 临时表不能嵌套或者建立多于两个

### 窗口函数
#### 利用rank()求分区间的最大值
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

#### 利用sum()求分区间的累积前缀
按天数累积
```sql
SELECT gender, day, SUM(score_points) OVER(PARTITION BY gender ORDER BY day) AS total
FROM Scores
```

#### 优先操作累积函数，再操作窗口函数
在下面的代码里，优先考虑group by Orders.product_id, customer_id，group之后每一行就可以定义count(Orders.product_id)，再按照该列对所有行进行rank
```sql
select Orders.product_id, product_name, customer_id, 
    rank() over (partition by customer_id order by count(Orders.product_id) desc) as rnk
from Orders
left join Products on Orders.product_id = Products.product_id
group by Orders.product_id, customer_id  
```

### Join
#### out join
不指定`on`的话，会将表A与表B的所有row都两两配对。
```sql
select *
from A
join B
```

### 遍历双表
#### 相当于两个for循环遍历两张表里的row，类似于join
```sql
select c1.seat_id, c2.seat_id
from Cinema c1, Cinema c2
where (c1.seat_id = c2.seat_id - 1 or c1.seat_id = c2.seat_id + 1) and c1.free = 1 and c2.free
order by c1.seat_id
```
