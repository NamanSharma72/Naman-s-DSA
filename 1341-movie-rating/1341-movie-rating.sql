# Write your MySQL query statement below
(select u.name as results
from movierating mr left join users u
    on mr.user_id = u.user_id
group by mr.user_id
order by count(*) desc , u.name asc
limit 1)

union all

(select m.title as results
from movierating mr left join movies m
    on mr.movie_id = m.movie_id
where created_at >= '2020-02-01' and created_at <= '2020-02-29'
group by mr.movie_id
order by avg(rating) desc , m.title asc
limit 1)