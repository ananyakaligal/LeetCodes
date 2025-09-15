-- Last updated: 9/16/2025, 12:08:10 AM
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
  ON c.id=o.customerId
WHERE o.customerId IS NULL
