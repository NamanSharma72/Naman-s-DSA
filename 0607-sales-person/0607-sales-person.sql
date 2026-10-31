# Write your MySQL query statement below
select s.name
from salesperson s left join company c
    on c.name = "red"
left join orders o
    on s.sales_id = o.sales_id and c.com_id = o.com_id
where o.order_id is null