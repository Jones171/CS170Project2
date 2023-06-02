#include "Object.h"

using namespace std;

Object::Object(){
    Class = 0;
}
void Object::print(){
    cout << "Class: " << Class << endl;

    for(int i = 0; i < features.size(); i++){
        cout << features.at(i) << " ";
    }
    cout << endl;
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
vector<float> Object::getFeatures(){
    return features;
}
