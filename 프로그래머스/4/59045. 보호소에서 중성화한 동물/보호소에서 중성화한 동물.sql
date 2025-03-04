-- 코드를 입력하세요
SELECT ins.animal_id, ins.animal_type, ins.name
from animal_ins as ins
join animal_outs as outs on outs.animal_id = ins.animal_id
where ins.sex_upon_intake Like 'Intact%' and (outs.sex_upon_outcome Like 'Spayed%' or outs.sex_upon_outcome like 'Neutered%')
order by animal_id