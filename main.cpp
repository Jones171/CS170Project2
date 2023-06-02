#include "headers.h"
#include "Classifier.h"
#include "Validator.h"
#include "Search.h"

using namespace std;

int main(){
    int numofFeatures;
    int algo;
    vector<int> features;
    cout << "Welcome to Jonas Tan's Feature Selection Algorithm" << endl;
    cout << "Please Enter number of features: ";
    cin >> numofFeatures;

    vector<int> currentSet = {3, 5, 7};
    int featuretoadd = 10;


    for(int i = 0; i < numofFeatures; i++){
        features.push_back(i);
    }

    cout << "Type the number of algorithm you want to run" << endl;
    cout << "Forward Selection" << endl;
    cout << "Backward Selection" << endl;
    cout << "Jonas's Special Algorithm" << endl;

    cin >> algo;
    if(algo == 1){
        ForwardSelection(features);
    }
    else if(algo == 2){
        BackwardSelection(features);
    }
    else if(algo == 3){
        // NN(interpretTxtFile());
        leaveOneOutCrossValidation(interpretTxtFile(), currentSet, featuretoadd);
    }
    return 0;
}