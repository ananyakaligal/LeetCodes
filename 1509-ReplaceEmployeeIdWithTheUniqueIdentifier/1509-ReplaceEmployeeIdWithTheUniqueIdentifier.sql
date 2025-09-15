-- Last updated: 9/16/2025, 12:03:04 AM
# Write your MySQL query statement below
SELECT euni.unique_id, e.name
FROM Employees e
LEFT JOIN EmployeeUNI euni
    ON e.id = euni.id;
