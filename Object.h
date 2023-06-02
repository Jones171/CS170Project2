#ifndef OBJECTS_H_
#define OBJECTS_H_

#include "headers.h"

using namespace std;

class Object{
    private:
        int Class; // Either 1 or 2
        vector <float> features;

    public:
        Object();
        void print();
        void setClass(int);
        int getClass();
        void appendFeature(float);
        vector<float> getFeatures();
};

#endif