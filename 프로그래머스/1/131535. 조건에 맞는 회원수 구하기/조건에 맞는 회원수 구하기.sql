-- 코드를 입력하세요
SELECT count(user_id) as USERS from user_info
where age >= 20 and age <= 29 and joined Like ('2021%')