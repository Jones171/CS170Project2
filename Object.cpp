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
void Object::setFeatures(vector<float> feature){
    features = feature;
}
void Object::setFeaturesIndex(int i, float value){
    features.at(i) = value;
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
int Object::getFeatureSize(){
    return features.size();
}
