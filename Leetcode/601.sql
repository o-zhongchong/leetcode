# Write your MySQL query statement below
select s1.id, s1.visit_date, s1.people from stadium s1, stadium s2, stadium s3
where s1.people >= 100
AND s2.people >= 100
AND s3.people >= 100
AND
(
    (
        s2.id = s1.id + 1
        AND s3.id = s2.id + 1
    )
    OR
    (
        s2.id = s1.id - 1
        AND s3.id = s2.id + 2
    )
    OR
    (
        s2.id = s1.id - 2
        AND s3.id = s2.id + 1
    )
)
group by s1.id, s1.visit_date, s1.people
order by s1.id