# Write your MySQL query statement below
select p.project_id, coalesce(round(avg(experience_years), 2), 0) as average_years
from
    Employee e
join 
    Project p
on 
    e.employee_id = p.employee_id
group by
    p.project_id;