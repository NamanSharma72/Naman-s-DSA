# Write your MySQL query statement below
select user_id as buyer_id , join_date , 
(select count(*) from orders o where o.buyer_id = u.user_id and order_date >= '2019-01-01' and order_date <= '2019-12-31') as orders_in_2019 from users u