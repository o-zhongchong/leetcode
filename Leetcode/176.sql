# Write your MySQL query statement below
select Salary as SecondHighestSalary from Employee
group by SecondHighestSalary
union all (select NULL as SecondHighestSalary)
order by SecondHighestSalary desc
limit 1,1