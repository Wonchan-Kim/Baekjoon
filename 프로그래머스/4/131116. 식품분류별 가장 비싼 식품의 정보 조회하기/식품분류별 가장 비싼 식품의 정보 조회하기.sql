-- 코드를 입력하세요
SELECT Category, Price as MAX_PRICE, PRODUCT_NAME
FROM Food_product
Where Price in (SELECT max(price) from food_product group by category)
            and category in ('과자', '국', '김치', '식용유')
order by MAX_PRICE DESC