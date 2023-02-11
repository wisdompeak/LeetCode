#### the Nth element 
order by XXX
limit 1 offset 10

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
#### 多个临时表
```sql
with temp as
(...),
temp2 as
(...)
select *
from temp2
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
