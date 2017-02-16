//
//  ObjVertex.hpp
//  ObjReader
//
//  Created by Jesús Martínez on 16/02/17.
//

#ifndef ObjVertex_hpp
#define ObjVertex_hpp

#include <stdio.h>

class ObjVertex {
private:
    float x;
    float y;
    float z;
public:
    float getX();
    float getY();
    float getZ();
};

#endif /* ObjVertex_hpp */
