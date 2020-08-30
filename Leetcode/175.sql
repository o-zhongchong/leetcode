# Write your MySQL query statement below
select p.FirstName, p.LastName, addr.City, addr.State
from Person p left join Address addr on p.PersonId = addr.PersonId