-- 코드를 입력하세요
SELECT Distinct car.car_id
from car_rental_company_car as car
join car_rental_company_rental_history as his on his.car_id = car.car_id
where date_format(his.start_date, '%m') = 10 and car.car_type='세단'
order by his.car_id desc