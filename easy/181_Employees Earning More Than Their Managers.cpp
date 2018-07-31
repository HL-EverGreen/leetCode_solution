# Write your MySQL query statement below
select a.Name as Employee
from Employee a, Employee b
where a.ManagerId=b.Id and a.Salary>b.Salary
#or use join operation
#select a.Name as Employee
#from Employee a join Employee b on a.ManagerId=B.Id
#where a.Salary>b.Salary
