-- Last updated: 9/16/2025, 12:08:12 AM
SELECT e.name AS Employee
FROM Employee e
JOIN Employee n
   ON e.managerId=n.id
WHERE e.salary>n.salary