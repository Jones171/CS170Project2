#include "Classifier.h"

using namespace std;

float NN(vector<Object> data){
    int correctlyClassified = 0; 
    float accuracy = 0;

    for(int i = 0; i < data.size(); i++){
        Object toClassify = data.at(i);
        int labelObject = data.at(i).getClass();

        float nnDistance = 1000;
        float nnLocation = -1;
        int nnLabel = -1;

        for(int j = 0; j < data.size(); j++){
            if(j == i){
                continue;
            }
            float distance = Euclidean(toClassify.getFeatures(), data.at(j).getFeatures());
            if(distance < nnDistance){
                nnDistance = distance;
                nnLocation = j;
                nnLabel = data.at(j).getClass();
            }
            // cout << "Ask if " << i << " is nearest neighbor with " << j << endl;
        }

        cout << "Object " << i << " is class" << labelObject << endl;
        cout << "Its nearest neighbor is " << nnLocation << " which is in class " << nnLabel << endl;
    }
    return accuracy;
}