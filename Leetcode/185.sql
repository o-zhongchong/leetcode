# Write your MySQL query statement below
select d.Name Department, e.Name Employee, e.Salary from Employee e
join Department d on e.DepartmentId = d.Id
where (select count(distinct Salary) from Employee e2 where e2.DepartmentId = e.DepartmentId AND e2.Salary > e.Salary) <= 2
