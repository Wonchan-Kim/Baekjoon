-- 코드를 입력하세요
SELECT b.category, sum(bs.sales) as total_sales
from BOOK as b
left join book_sales as bs on b.book_id = bs.book_id
where bs.sales_date like '2022-01%'
group by b.category
order by b.category 