#ifndef _CELL_H_
#define _CELL_H_

#include "headers.h"

using namespace std;

class Cell
{
private:
    bool root;
    Cell* parent;

    vector<int> currentFeatures;
    vector<Cell*> children;

public:
    Cell(bool isroot, Cell* tempparent){
        root = isroot;
        parent = tempparent;
    }
    ~Cell();
    void AssignChild(Cell* curr, vector<int> features){

    }
    void combineChildren(Cell* curr){

    }
};

#endif