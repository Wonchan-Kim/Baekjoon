SELECT g.user_id,
       g.nickname,
       SUM(b.price) AS total_sales
  FROM used_goods_board b
  JOIN used_goods_user  g 
       ON b.writer_id = g.user_id
 WHERE b.status = 'DONE'
 GROUP BY g.user_id, g.nickname
HAVING SUM(b.price) >= 700000
 ORDER BY SUM(b.price);
