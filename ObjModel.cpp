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

/**
 Constructor. Read obj file as text file and create OBJModel.
 @param fileName Name of the obj file with extension.
 **/
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
                // Create OBJ object and add it to vector.
                case 'o': {
                    char* name = getSplittedLine(line).at(0);
                    ObjObject object = ObjObject(string(name));
                    this->objects.push_back(object);
                    break;
                }
                // Create vertex and add it to vector.
                case 'v': {
                    vector<char*> coords = getSplittedLine(line);
                    ObjVertex vertex = ObjVertex(::atof(coords.at(0)), ::atof(coords.at(1)), ::atof(coords.at(2)));
                    vertices.push_back(vertex);
                    break;
                }
                // Add vertices indexes to the last OBJ object created.
                case 'f': {
                    vector<int> faceVector;
                    vector<char*> facesIndexes = getSplittedLine(line);
                    
                    for(auto &faceIndex : facesIndexes)
                    {
                        if(faceIndex != NULL)
                            faceVector.push_back(atoi(faceIndex) - 1);
                    }
                    objects.back().addFaceVector(faceVector);
                    /*for(int i = 0; i < facesIndexes.size(); i++)
                    {
                       lastObject.getFacesIndexes().push_back(atoi(facesIndexes.at(i)) - 1);
                    }*/
                    break;
                }

            }
            cout << endl;
        }
        file.close();
    }
    
    else cout << "Unable to open file";
}

/**
 Receive a string and split it in words separated by space.
 @param line Line to be splitted.
 @return vector with words.
 **/
vector<char*> ObjModel::getSplittedLine(string line)
{
    vector<char*> splitted;
    char * lineWord = nullptr;
    
    lineWord = strtok (const_cast<char *>(line.c_str()), " ");
    while (lineWord != NULL)
    {
        cout << lineWord;
        lineWord = strtok (NULL, " ");
        splitted.push_back(lineWord);
    }
    
    return splitted;
}

/**
 Read all OBJ Model info and print.
 **/
void ObjModel::print()
{
    cout << "**** OBJ MODEL *******" << endl;
    
    for (auto &object : objects)
    {
        // Print vertices
        cout << "o " << object.getName() << endl;
        for(auto &faceVector : object.getFaces())
        {
            for(auto faceIndex :faceVector)
            {
                cout << "v ";
                vertices.at(faceIndex).print();
            }
        }
        
        // Print faces
        for(auto &faceVector : object.getFaces())
        {
            cout << "f ";
            for(auto faceIndex :faceVector)
            {
                cout << faceIndex + 1 << " ";
            }
            cout << endl;
        }
    }
}
