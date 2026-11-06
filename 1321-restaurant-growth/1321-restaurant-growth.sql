# Write your MySQL query statement below
with firstTable as (
    select visited_on , sum(amount) as amount
    from customer
    group by visited_on
),
secondTable as(
    select visited_on , sum(amount) over(order by visited_on rows between 6 preceding and current row) as sum_amount , avg(amount) over(order by visited_on rows between 6 preceding and current row) as average_amount
    , row_number() over(order by visited_on) as num
    from firstTable
)
select visited_on , sum_amount as amount , round(average_amount,2) as average_amount
from secondTable
where num >= 7
