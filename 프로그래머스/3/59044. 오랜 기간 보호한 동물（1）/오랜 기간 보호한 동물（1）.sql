-- 코드를 입력하세요
SELECT ins.name, ins.datetime
from animal_ins as ins
left join animal_outs as outs on outs.animal_id = ins.animal_id -- 왼쪽 매치시키고 오른쪽 해당 값없으면 null로 채움. 이 테이블의 이름은 가상 테이블
where outs.animal_id is NULL -- 이 가상 테이블에서 outs.aninmal_id의 값이 null 인걸 선택함
order by ins.datetime
limit 3
