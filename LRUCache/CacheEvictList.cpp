//
//  CacheEvictList.cpp
//  LRUCache
//
//  Created by Iain Nash on 9/23/15.
//  Copyright © 2015 Iain Nash. All rights reserved.
//

#include "CacheEvictList.hpp"

Node* CacheEvictList::add(std::string key) {
  Node *new_node = new Node(key, this->tail, NULL);
  if (this->tail) {
    this->tail->next = new_node;
  }
  this->tail = new_node;
  if (this->head == NULL) {
    this->head = this->tail;
  }
  this->size += 1;
  return new_node;
}

void CacheEvictList::update(Node *node) {
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }
  this->tail->next = node;
  node->prev = this->tail;
  this->tail = node;
}

std::string *CacheEvictList::get_evict() {
  if (this->size > this->max_size) {
    Node* to_remove = this->head;
    this->head = this->head->next;
    std::string *key = &to_remove->key;
    std::string *copied_key = new std::string(*key);
    //delete to_remove;
    this->size -= 1;
    return copied_key;
  }
  return NULL;
}