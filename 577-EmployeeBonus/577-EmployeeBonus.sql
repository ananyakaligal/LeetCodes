-- Last updated: 9/16/2025, 12:05:57 AM
SELECT e.name, b.bonus
FROM Employee e
LEFT JOIN Bonus b
  ON e.empId= b.empId
WHERE b.bonus <1000 OR b.bonus IS NULL;