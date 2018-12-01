//
//  index_long.h
//  Vasern
//
//  Created by Hieu (Jack) Nguyen on 26/11/18.
//  Copyright © 2018 Hieu (Jack) Nguyen. All rights reserved.
//

#ifndef index_long_h
#define index_long_h

#include "index_t.h"

namespace vs {
    
    class index_long: public index_t {
    public:
        
        index_long()
        : index_t()
        { }
        
        void push(value_t* key, value_ptr value) {
            if (items.count(key->long_value()) == 0) {
                items[key->long_value()] = std::vector<value_ptr> { value };
            } else {
                items[key->long_value()].push_back(value);
            }
        }
        
        void update(value_t* old_key, value_t* key) {
            auto values = items[old_key->long_value()];
            items.erase(old_key->long_value());
            items[key->long_value()] = values;
        }
        
        void remove(value_t* key) {
            items.erase(key->long_value());
        }
        
        std::vector<value_ptr> get(value_t* key) {
            return items[key->long_value()];
        }
        
    private:
        std::unordered_map<long, std::vector<value_ptr>> items;
    };
    
}

#endif /* index_long_h */
