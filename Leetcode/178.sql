# Write your MySQL query statement below
SELECT s.Score, (SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= s.Score) as `Rank`
FROM Scores s ORDER BY Score DESC;
