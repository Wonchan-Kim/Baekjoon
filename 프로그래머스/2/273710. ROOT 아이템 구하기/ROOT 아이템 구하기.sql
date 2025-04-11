Select Item_info.item_id as Item_id, ITEM_NAME
from Item_info
join Item_tree on item_info.item_id = Item_tree.item_id
where Parent_item_id is null