SELECT count(*) as FISH_COUNT
From FISH_INFO
Group by Length
Having Length IS NULL