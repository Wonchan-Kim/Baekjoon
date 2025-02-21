-- 코드를 입력하세요
SELECT pt_name, pt_no, gend_cd, age,
    case
        when TLNO is NULL then 'NONE'
        else TLNO
        end as tlno
from patient
where age <= 12 and gend_cd = 'W'
order by age desc, pt_name asc

