# Write your MySQL query statement below
select p1.product_id , ifnull((select p2.new_price from products p2 where p2.product_id = p1.product_id and p2.change_date <= '2019-08-16' order by p2.change_date desc limit 1) , 10) as price
from (select distinct product_id from products) p1