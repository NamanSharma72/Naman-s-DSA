# Write your MySQL query statement below
select round(count(case when a1.event_date= (select min(event_date) from activity where player_id = a1.player_id) + interval 1 day then 1 end)/count(distinct player_id) , 2) as fraction
from activity a1