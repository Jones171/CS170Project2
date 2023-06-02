#include "Classifier.h"

using namespace std;

float NN(vector<Object> data){
    int correctlyClassified = 0; 
    float accuracy = 0;

    for(int i = 0; i < data.size(); i++){
        // Object toClassify = data.at(i);
        int labelObject = data.at(i).getClass();

        float nnDistance = std::numeric_limits<float>::infinity();
        float nnLocation = std::numeric_limits<float>::infinity();
        int nnLabel = -1;

        for(int j = 0; j < data.size(); j++){
            if(j == i){
                continue;
            }
            float distance = Euclidean(data.at(i).getFeatures(), data.at(j).getFeatures());
            // cout << "Distance: " << distance << endl;
            if(distance < nnDistance){
                nnDistance = distance;
                nnLocation = j;
                nnLabel = data.at(j).getClass();
            }
            // cout << "Ask if " << i << " is nearest neighbor with " << j << endl;
        }
        if(labelObject == nnLabel){
            correctlyClassified += 1; 
        }
        // cout << "Object " << i << " is class " << labelObject << endl;
        // cout << "Its nearest neighbor is " << nnLocation << " which is in class " << nnLabel << endl;
    }
    
    for(int i = 0; i < data.size(); i++){
        data.at(i).print();
    }

    accuracy = (float)correctlyClassified/(float)data.size() * 100;

    return accuracy;
}