-- https://leetcode.com/problems/queries-quality-and-percentage/submissions/2193478149

# Write your MySQL query statement below
# Return query name
SELECT query_name,
    # Return quality calculation per group
    # (I suspect position is also a keyword, so it is wrapped in backticks)
    ROUND(SUM(rating/`position`)/COUNT(query_name), 2) AS quality,
    # Return percentage calculation per group
    ROUND(100*SUM(rating < 3)/COUNT(query_name), 2) AS poor_query_percentage
# Table to use
FROM Queries
# Group entries by query name
GROUP BY query_name