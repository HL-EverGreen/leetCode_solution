# Write your MySQL query statement below

#select name as 'Customers'
#from customers
#where id not in
#(
#    select customerid from orders
#);

select name as 'Customers'
from customers left join orders on customers.id=orders.customerid
where customerid is NULL;