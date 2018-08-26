# Write your MySQL query statement below
select a.id
from Weather as a, Weather as b
where TO_DAYS(a.recorddate)-TO_DAYS(b.recorddate)=1 and a.temperature>b.temperature;