//
//  Node.hpp
//  LRUCache
//
//  Created by Iain Nash on 9/23/15.
//  Copyright © 2015 Iain Nash. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <string>

class Node {
public:
  Node(std::string key, Node *prev, Node *next) :
    key(key), prev(prev), next(next) {
    // None.
  }
  std::string key;
  Node *prev;
  Node *next;
};

#endif /* Node_hpp */
