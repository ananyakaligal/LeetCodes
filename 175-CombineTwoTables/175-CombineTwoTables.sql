-- Last updated: 9/16/2025, 12:08:15 AM
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a
ON p.personId = a.personId;
