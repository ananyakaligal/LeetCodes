-- Last updated: 9/16/2025, 12:08:13 AM
SELECT MAX(salary) AS SecondHighestSalary
FROM (
  SELECT salary,
         DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
  FROM Employee
) ranked
WHERE rnk = 2;
