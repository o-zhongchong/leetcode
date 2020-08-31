# Write your MySQL query statement below
select distinct log1.Num as ConsecutiveNums from `Logs` log1
join `Logs` log2 on log1.Id = log2.Id + 1
join `Logs` log3 on log1.Id = log3.Id - 1
where log1.Num = log2.Num AND log2.Num = log3.Num
