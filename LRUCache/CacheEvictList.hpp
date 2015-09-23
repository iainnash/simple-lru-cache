//
//  CacheEvictList.hpp
//  LRUCache
//
//  Created by Iain Nash on 9/23/15.
//  Copyright © 2015 Iain Nash. All rights reserved.
//

#ifndef CacheEvictList_hpp
#define CacheEvictList_hpp

#include "Node.hpp"
#import <string>

class CacheEvictList {
public:
  CacheEvictList(int max_size) : max_size(max_size) {}
  int max_size;
  int size;
  Node *head;
  Node *tail;
  Node *add(std::string key);
  void update(Node* node);
  std::string *get_evict();
};

#endif /* CacheEvictList_hpp */
