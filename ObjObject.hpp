//
//  ObjObject.hpp
//  ObjReader
//
//  Created by Jesús Martínez on 16/02/17.
//

#ifndef ObjObject_hpp
#define ObjObject_hpp

#include <stdio.h>
#include <string>
#include <vector>

class ObjObject {
private:
    std::string name;
    std::vector<int> faces;
};

#endif /*ObjObject_hpp */
