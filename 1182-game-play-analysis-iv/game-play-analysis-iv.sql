# Write your MySQL query statement below
with cte1 as (
    select 
        player_id, min(event_date) as first_login
    from 
        Activity
    group by
        player_id
),
cte2 as (
    select *, 
        date_add(first_login, interval 1 day) as next_day
    from 
        cte1
)

select round(
    (select count(player_id)
from
    Activity
where
    (player_id, event_date)
in
    (select player_id, next_day from cte2)) /
    (select count(distinct player_id) from Activity), 2) as fraction;