# Write your MySQL query statement below
WITH cte1 AS (
    SELECT 
        player_id, 
        MIN(event_date) AS first_login
    FROM 
        Activity
    GROUP BY
        player_id
),
cte2 AS (
    SELECT 
        player_id, 
        DATE_ADD(first_login, INTERVAL 1 DAY) AS next_day
    FROM 
        cte1
)
SELECT 
    ROUND(
        (SELECT COUNT(*) 
         FROM Activity A
         JOIN cte2 C ON A.player_id = C.player_id AND A.event_date = C.next_day) / 
        (SELECT COUNT(DISTINCT player_id) FROM Activity), 
    2) AS fraction;