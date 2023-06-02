#include "Classifier.h"

using namespace std;

float NN(vector<float> data, vector<float> labels){
    int correctlyClassified = 0; 
    float accuracy = 0;

    for(int i = 0; i < data.size(); i++){
        float toClassify = data.at(i);
        //Figure out what this is 
        if(i % 10 == 0){
            int labelObject = labels.at(i/10);
        }

        float nnDistance = -1;
        float nnLocation = -1;

        cout << "Looping over i, at the " << i << " location" << endl;
        cout << "The " << i << "th object is in class " << labels.at(i) << endl;
    }
    return accuracy;
}