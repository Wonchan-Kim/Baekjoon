-- 코드를 입력하세요
SELECT first_half.flavor
from first_half, icecream_info
where first_half.flavor = icecream_info.flavor and first_half.total_order > 3000 and icecream_info.ingredient_type = 'fruit_based'
order by total_order desc