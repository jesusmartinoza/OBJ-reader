//
//  ObjModel.hpp
//  ObjReader
//
//  Created by Jesús Martínez on 16/02/17.
//

#ifndef ObjModel_hpp
#define ObjModel_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "ObjVertex.hpp"
#include "ObjObject.hpp"

class ObjModel {
private:
    std::vector<ObjVertex> vertices;
    std::vector<ObjObject> objects;
public:
    void print();
};

#endif /* ObjModel_hpp */
