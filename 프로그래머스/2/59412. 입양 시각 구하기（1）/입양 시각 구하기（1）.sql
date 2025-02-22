SELECT HOUR(datetime) AS HOUR, COUNT(*) AS COUNT 
FROM animal_outs
WHERE HOUR(datetime) >= 9 AND HOUR(datetime) < 20  -- (1) 먼저 필터링
GROUP BY HOUR(datetime)  -- (2) 그룹화
ORDER BY HOUR;  -- (3) 정렬
