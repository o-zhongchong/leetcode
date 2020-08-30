CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  Set N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select Salary as SecondHighestSalary from Employee
      group by SecondHighestSalary
      union all (select NULL as SecondHighestSalary)
      order by SecondHighestSalary desc
      limit N,1
  );
END