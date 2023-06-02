#include "Classifier.h"

using namespace std;

float NN(vector<Object> data){
    int correctlyClassified = 0; 
    float accuracy = 0;

    for(int i = 0; i < data.size(); i++){
        Object toClassify = data.at(i);
        int labelObject = data.at(i).getClass();

        float nnDistance = -1;
        float nnLocation = -1;

        // for(int j = 0; j < data.size(); j++){
        //     if(j == i){
        //         continue;
        //     }
        //     cout << "Ask if " << i << " is nearest neighbor with" << j << endl;
        // }

        cout << "Looping over i, at the " << i << " location" << endl;
        cout << "The " << i << "th object is in class " << labelObject << endl;
    }
    return accuracy;
}