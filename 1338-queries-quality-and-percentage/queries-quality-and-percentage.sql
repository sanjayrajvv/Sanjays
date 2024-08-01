# Write your MySQL query statement below
SELECT 
    query_name, 
    ROUND(SUM(rating / position) / COUNT(query_name), 2) AS quality,
    ROUND((SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*)), 4) * 100 
    AS poor_query_percentage
FROM 
    Queries
WHERE 
    rating IS NOT NULL AND 
    position IS NOT NULL AND 
    query_name IS NOT NULL
GROUP BY 
    query_name;
