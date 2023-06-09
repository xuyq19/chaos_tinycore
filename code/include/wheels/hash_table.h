#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "../../include/defs.h"
#include "linked_list.h"
struct hash_table_node {
  struct linked_list_node confliced_list;
};

struct hash_table {
  uint64_t buffer_length;
  uint64_t (*is_equal)(struct hash_table_node *nodeA,
                       struct hash_table_node *nodeB);
  uint64_t (*get_hash)(struct hash_table_node *node);
  struct hash_table_node *buffer;
};

static inline void hash_table_init(struct hash_table *table) {
  for (uint64_t i = 0; i < table->buffer_length; i += 1) {
    linked_list_init(&(table->buffer[i].confliced_list));
  }
}

static inline struct hash_table_node *
hash_table_get(struct hash_table *table, struct hash_table_node *node) {
  uint64_t hash = table->get_hash(node) % table->buffer_length;
  struct linked_list_node *confliced_list =
      &(table->buffer[hash].confliced_list);
  struct linked_list_node *list_node;
  struct hash_table_node *hash_node;
  for_each_node(list_node, confliced_list) {
    hash_node =
        _container_of(list_node, struct hash_table_node, confliced_list);
    if (table->is_equal(node, hash_node))
      break;
  }
  if (list_node == confliced_list)
    return (struct hash_table_node *)NULL;
  return hash_node;
}

static inline void hash_table_set(struct hash_table *table,
                                  struct hash_table_node *node) {
  uint64_t hash = table->get_hash(node) % table->buffer_length;
  struct linked_list_node *confliced_list =
      &(table->buffer[hash].confliced_list);
  insert_node_to_first(confliced_list, &(node->confliced_list));
}

static inline struct hash_table_node *
hash_table_del(struct hash_table *table, struct hash_table_node *node) {
  struct hash_table_node *hash_node = hash_table_get(table, node);
  if (hash_node)
    delete_node(&(hash_node->confliced_list));
  return hash_node;
}

#endif
