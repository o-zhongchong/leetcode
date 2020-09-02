# Write your MySQL query statement below
select t.Request_at Day, round(sum(case when t.Status like 'cancelled_by_%' then 1 else 0 end)/count(Id), 2) 'Cancellation Rate' from Trips t
join Users u1 on t.Client_Id=u1.Users_Id AND u1.Banned='No'
join Users u2 on t.Driver_id=u2.Users_id AND u2.Banned='No'
where t.Request_at >= '2013-10-01' AND t.Request_at <= '2013-10-03'
group by t.Request_at
order by t.Request_at