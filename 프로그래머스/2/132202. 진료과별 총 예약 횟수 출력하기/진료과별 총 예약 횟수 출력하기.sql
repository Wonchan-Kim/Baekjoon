SELECT mcdp_cd AS 진료과코드, COUNT(*) AS `5월예약건수`
FROM appointment
WHERE LEFT(apnt_ymd, 7) = '2022-05'
GROUP BY mcdp_cd
ORDER BY `5월예약건수` asc, `진료과코드` ASC;
