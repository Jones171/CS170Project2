#include "Object.h"

using namespace std;

Object::Object(){
    Class = 0;
}
void Object::setClass(int i){
    Class = i;
}
int Object::getClass(){
    return Class;
}
void Object::appendFeature(float i){
    features.push_back(i);
}
void Object::getFeatures(){
    return features;
}
