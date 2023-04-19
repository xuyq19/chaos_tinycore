#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stddef.h>
#include <stdint.h>

/**
 * @brief 双向循环列表
 *
 */
struct linked_list_node {
  struct linked_list_node *next;
  struct linked_list_node *prev;
};

/**
 * @brief 初始化一个双向循环列表
 *
 * @param list
 */
static inline void linked_list_init(struct linked_list_node *list) {
  list->next = list;
  list->prev = list;
}

/**
 * @brief 在某节点前面添加一个节点
 * @param new_node 新节点, 不能为NULL
 * @param prev 要添加到的节点, 不能为NULL
 */
static inline void insert_node_before(struct linked_list_node *new_node,
                                      struct linked_list_node *prev) {
  new_node->next = prev;
  new_node->prev = prev->prev;
  prev->prev->next = new_node;
  prev->prev = new_node;
}

/**
 * @brief 在某节点后面添加一个节点
 * @param new_node 新节点, 不能为NULL
 * @param next 要添加到的节点, 不能为NULL
 *
 */
static inline void insert_node_after(struct linked_list_node *new_node,
                                     struct linked_list_node *next) {
  new_node->next = next->next;
  new_node->prev = next;
  next->next->prev = new_node;
  next->next = new_node;
}

/**
 * @brief 删除一个节点
 *
 * @param target 要删除的节点，不能为NULL
 */
* / static inline void delete_node(struct linked_list_node *target) {
  target->next->prev = target->prev;
  target->prev->next = target->next;
}

/**
 * @brief 判断一个列表是否为空
 *
 * @param list 要判断的列表
 */
static inline uint64_t linked_list_empty(struct linked_list_node *list) {
  return list->next == list;
}

/**
 * @brief Get the first node object
 *
 * @param list
 * @return struct linked_list_node*
 */
static inline struct linked_list_node *
get_first_node(struct linked_list_node *list) {
  return list->next;
}

/**
 * @brief Get the last node object
 *
 * @param list
 * @return struct linked_list_node*
 */
static inline struct linked_list_node *
get_last_node(struct linked_list_node *list) {
  return list->prev;
}