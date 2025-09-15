-- Last updated: 9/16/2025, 12:08:08 AM
SELECT d.name AS Department, e.name AS Employee, e.salary
FROM Employee e
INNER JOIN Department d
    ON e.departmentId = d.id
INNER JOIN (
    SELECT departmentId, MAX(salary) AS max_salary
    FROM Employee
    GROUP BY departmentId
) m
    ON e.departmentId = m.departmentId
   AND e.salary = m.max_salary;
