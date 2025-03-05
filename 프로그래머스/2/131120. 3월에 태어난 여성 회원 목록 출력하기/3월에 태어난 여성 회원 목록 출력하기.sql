-- 코드를 입력하세요
SELECT prof.member_id, prof.member_name, prof.gender, DATE_FORMAT(prof.date_of_birth, '%Y-%m-%d') as DATE_OF_BIRTH
from member_profile prof
where TLNO is not NULL and DATE_FORMAT(prof.date_of_birth, '%m') = '03' and GENDER='W'
order by member_id