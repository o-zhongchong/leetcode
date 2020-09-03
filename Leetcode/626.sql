# Write your MySQL query statement below
select s1.id, s2.student from seat s1, seat s2
where
( s1.id % 2 = 1 AND s1.id = s2.id - 1 )
OR
( s1.id % 2 = 0 AND s1.id = s2.id + 1)
OR
( s1.id % 2 = 1 AND s1.id = (select max(id) from seat s3) AND s1.id = s2.id )
order by s1.id