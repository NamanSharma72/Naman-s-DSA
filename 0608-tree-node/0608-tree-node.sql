# Write your MySQL query statement below
select t1.id , 
case when t1.p_id is null then 'Root' 
when exists (select 1 from tree t2 where t2.p_id = t1.id) then 'Inner'
else 'Leaf'
end as type
from tree t1