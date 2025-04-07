-- 코드를 입력하세요
SELECT Floor(Price/10000) * 10000 as PRICE_GROUP, COUNT(*) as PRODUCTS 
from product
group by Floor(Price/10000) * 10000
order by PRICE_GROUP ASC