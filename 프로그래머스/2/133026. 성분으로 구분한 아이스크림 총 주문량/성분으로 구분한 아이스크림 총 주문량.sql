-- 코드를 입력하세요
SELECT i.ingredient_type, sum(f.total_order) as total_order
from first_half as f
right join icecream_info as i on f.flavor = i.flavor
group by i.ingredient_type 