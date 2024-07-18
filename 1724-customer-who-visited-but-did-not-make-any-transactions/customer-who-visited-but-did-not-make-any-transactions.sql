# Write your MySQL query statement belows
select customer_id, count(visit_id) as count_no_trans
from Visits
where visit_id not in (
    select visit_id 
    from transactions
)
group by customer_id;