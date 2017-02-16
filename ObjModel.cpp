//
//  ObjModel.cpp
//  ObjReader
//
//  Created by Jesús Martínez on 16/02/17.
//  Main class that represent the entire OBJ model.
//  It contains a list of vertices and objects.
//

#include "ObjModel.hpp"
#include <iostream>
#include <fstream>

using namespace std;

ObjModel::ObjModel(string fileName)
{
    cout << "File name: " << fileName << "\n";
    string line;
    ifstream file (fileName);
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            cout << line << '\n';
        }
        file.close();
    }
    
    else cout << "Unable to open file";
}
