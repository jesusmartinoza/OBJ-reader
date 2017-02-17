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
#include <cstring>
#include <fstream>

using namespace std;

ObjModel::ObjModel(string fileName)
{
    cout << "File name: " << fileName << "\n" << endl;
    
    string line;
    ifstream file (fileName);
    
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            cout << line << '\n';
            switch (line[0]) {
                case 'o':
                    getSplittedLine(line);
                    break;
                case 'v':
                    vector<char*> coords = getSplittedLine(line);
                    ObjVertex vertex = ObjVertex(::atof(coords.at(0)), ::atof(coords.at(1)), ::atof(coords.at(2)));
                    vertices.push_back(vertex);
                    break;
            }
            cout << endl;
        }
        file.close();
    }
    
    else cout << "Unable to open file";
}

vector<char*> ObjModel::getSplittedLine(string line)
{
    vector<char*> splitted;
    char * lineWord = nullptr;
    
    lineWord = strtok (const_cast<char *>(line.c_str()), " ");
    while (lineWord != NULL)
    {
        cout << lineWord;
        splitted.push_back(lineWord);
        lineWord = strtok (NULL, " ");
    }
    
    return splitted;
}
