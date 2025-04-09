SELECT Count(*) as FISH_COUNT, Month(Time) as Month
From Fish_info
Group by Month(TIME)
Order by Month(TIME) asc