# Write your MySQL query statement below
select person_name from (select person_name , turn , person_id , weight , sum(weight) over(order by turn) as total_weight
from queue q1)q1
where total_weight <= 1000
order by total_weight desc
limit 1