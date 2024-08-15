# Write your MySQL query statement below
SELECT
    customer_id,
    COUNT(*) AS count_no_trans
FROM
    Visits as v
    LEFT JOIN Transactions AS t ON v.visit_id = t.visit_id
WHERE
    t.visit_id IS NULL
GROUP BY
    customer_id

