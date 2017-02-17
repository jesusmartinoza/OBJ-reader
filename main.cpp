//
//  main.cpp
//  ObjReader
//
//  Created by Jesús Martínez on 16/02/17.
//

#include <iostream>
#include "ObjModel.hpp"

int main(int argc, const char * argv[]) {
    if(argc < 2) {
        cerr << "File name required" << endl;
        return 1;
    }
    
    ObjModel model(argv[1]);
    return 0;
}
