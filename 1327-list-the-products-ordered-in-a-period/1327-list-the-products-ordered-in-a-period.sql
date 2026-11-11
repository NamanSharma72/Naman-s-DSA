# Write your MySQL query statement below
select product_name , sum(unit) as unit
from products p left join orders o
    on p.product_id = o.product_id
where order_date >= '2020-02-01' and order_date <= '2020-02-29'
group by product_name
having sum(unit) >= 100