Select YEAR(YM) as year, ROUND(AVG(PM_val1),2) as 'PM10', ROUND(AVG(pm_val2),2) as 'PM2.5'
from air_pollution
group by Year, location2
Having location2 = '수원'
order by YEAR ASC