-- Last updated: 9/16/2025, 12:06:00 AM
SELECT e.name
FROM Employee e
JOIN Employee r
  ON e.id = r.managerId
GROUP BY e.id, e.name
HAVING COUNT(*) >= 5;
