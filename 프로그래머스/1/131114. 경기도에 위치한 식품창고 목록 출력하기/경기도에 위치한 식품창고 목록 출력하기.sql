-- 코드를 입력하세요
SELECT warehouse_id, warehouse_name, address,
    case
        when freezer_yn is NUll then  'N'
        else freezer_yn
        end as FREEZER_YN
from food_warehouse
where address LIKE '경기%'
order by warehouse_id 