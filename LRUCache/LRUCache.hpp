//
//  LRUCache.hpp
//  LRUCache
//
//  Created by Iain Nash on 9/23/15.
//  Copyright © 2015 Iain Nash. All rights reserved.
//

#ifndef LRUCache_hpp
#define LRUCache_hpp

#include <string>
#include <map>

#include "CacheEvictList.hpp"

template <class K>
class LRUCache {
public:
  LRUCache(int max_size) : cache_evict(max_size) {
    // Nothing here.
  }
  std::map<std::string, std::pair<K, Node*>> cache;
  CacheEvictList cache_evict;
  void put(std::string key, K val) {
    if (cache.count(key) == 1) {
      std::pair<K, Node*> cval = cache[key];
      cval.first = val;
      cache_evict.update(cval.second);
    } else {
      Node *new_node = cache_evict.add(key);
      cache[key] = std::pair<K, Node*>(val, new_node);
      
      std::string* evicted = cache_evict.get_evict();
      if (evicted != NULL) {
        cache.erase(*evicted);
        delete evicted;
      }
    }
  }
  bool exists(std::string key) {
    return cache.count(key) == 1;
  }
  K get(std::string key) {
    try {
      std::pair<K, Node*> val = cache.at(key);
      cache_evict.update(val.second);
      return val.first;
    } catch (std::out_of_range e) {
      return NULL;
    }
  }
};

#endif /* LRUCache_hpp */
