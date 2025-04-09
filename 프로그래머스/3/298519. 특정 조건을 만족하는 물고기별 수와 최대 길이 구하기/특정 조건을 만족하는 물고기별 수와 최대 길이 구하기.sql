Select Count(*) as FISH_COUNT, MAX(Length) as MAX_LENGTH, FISH_TYPE
From FISH_INFO
GROUP BY FISH_Type
Having avg(length) >= 33
Order by Fish_Type asc