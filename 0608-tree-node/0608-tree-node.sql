# Write your MySQL query statement below
with firstTable as (
    select t1.id as id  , t1.p_id as p_id , (select count(*) from tree t2 where t2.p_id = t1.id) as count_child from tree t1)

select id , 
case 
    when p_id is null then 'Root'
    when count_child > 0 then 'Inner'
    else 'Leaf'
end as type 
from firstTable