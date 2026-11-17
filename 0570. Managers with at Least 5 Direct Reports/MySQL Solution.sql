-- https://leetcode.com/problems/managers-with-at-least-5-direct-reports/submissions/2196384295

# Get names...
SELECT name
FROM Employee
# ...of employees whose ID satisfy the following subquery:
WHERE id IN (
    # Get manager IDs...
    SELECT managerId
    FROM Employee
    # ...that are not null...
    WHERE managerId IS NOT NULL
    # ...and that, when the entries are grouped by manager ID, have >= 5
    # corresponding entries.
    GROUP BY managerId
    HAVING COUNT(id) >= 5
)