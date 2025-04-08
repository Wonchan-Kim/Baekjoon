Select COUNT(*) as FISH_COUNT, i.FISH_NAME
From Fish_info as f
inner join fish_name_info as i on f.fish_type = i.fish_type
group by f.fish_type, i.fish_name
order by Fish_count desc