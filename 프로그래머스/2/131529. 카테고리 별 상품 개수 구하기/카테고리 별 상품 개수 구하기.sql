-- 코드를 입력하세요
SELECT LEFT(Product_code, 2) as prefix, count(*)
from product
group by prefix