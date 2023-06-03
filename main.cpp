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

    // For smallset
    // vector<int> currentSet = {3, 5, 7};
    // For largeset
    vector<int> currentSet = {1, 15, 27};
    int featuretoadd = 27;


    for(int i = 0; i < numofFeatures; i++){
        features.push_back(i);
    }

    cout << "Type the number of algorithm you want to run" << endl;
    cout << "Forward Selection" << endl;
    cout << "Backward Selection" << endl;
    cout << "Jonas's Special Algorithm" << endl;

    cin >> algo;
    if(algo == 1){
        auto start = chrono::system_clock::now();
        ForwardSelection(features);
        auto end = chrono::system_clock::now();
 
        chrono::duration<double> elapsed_seconds = end - start;
        time_t end_time = chrono::system_clock::to_time_t(end);
    
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s"
                << std::endl;

    }
    else if(algo == 2){
        BackwardSelection(features);
    }
    else if(algo == 3){
        // NN(interpretTxtFile());
        cout << "Accuracy: " << leaveOneOutCrossValidation(interpretTxtFile(), currentSet, featuretoadd);
    }
    return 0;
}