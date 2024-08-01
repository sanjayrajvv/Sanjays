# Write your MySQL query statement below
select r.contest_id, round(count(r.user_id) / (select count(*) from Users), 4) * 100 as percentage
from
    Users u
join 
    Register r
on
    u.user_id = r.user_id
group by 
    contest_id
order by
    percentage desc, contest_id asc;