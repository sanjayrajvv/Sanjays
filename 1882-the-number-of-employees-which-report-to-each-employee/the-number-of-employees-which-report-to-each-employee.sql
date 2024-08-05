# Write your MySQL query statement below
SELECT
    mgr.employee_id,
    mgr.name,
    COUNT(emp.employee_id) as reports_count,
    ROUND(
        AVG(emp.age)
    ) as average_age
FROM
    Employees emp
    JOIN Employees mgr on emp.reports_to = mgr.employee_id
GROUP BY
    employee_id
ORDER BY
    employee_id
