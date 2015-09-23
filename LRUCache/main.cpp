//
//  main.cpp
//  LRUCache
//
//  Created by Iain Nash on 9/23/15.
//  Copyright © 2015 Iain Nash. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "LRUCache.hpp"

std::string make_prefix(int num) {
  std::ostringstream ss;
  ss << "test" << num;
  return ss.str();
}

int main(int argc, const char * argv[]) {
  // Testing Cache
  LRUCache<int> cache(10);
  for (int i = 0; i < 20; i++) {
    cache.put(make_prefix(i), i*10);
  }
  for (int i = 0; i < 20; i++){
    std::string key = make_prefix(i);
    std::cout << key << ": ";
    if (cache.exists(key)) {
      std::cout << cache.get(key);
    } else {
      std::cout << "<none>";
    }
    std::cout << std::endl;
  }
}
