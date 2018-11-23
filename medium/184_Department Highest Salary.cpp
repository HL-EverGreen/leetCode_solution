# Write your MySQL query statement below
select dep.Name as Department, emp.Name as Employee, emp.Salary
from Department dep join Employee emp on emp.DepartmentId = dep.Id
and emp.salary = (select max(Salary) from Employee emp2 where emp2.DepartmentId = dep.Id)