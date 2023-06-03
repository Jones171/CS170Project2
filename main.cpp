#include "headers.h"
#include "Classifier.h"
#include "Validator.h"
#include "Search.h"

using namespace std;

int main(){
    string fileName;
    int algo;
    vector<int> features;
    cout << "Welcome to Jonas Tan's Feature Selection Algorithm" << endl;
    cout << "Type in the name of the file to test: ";
    cin >> fileName;

    // For smallset
    // vector<int> currentSet = {3, 5, 7};
    // For largeset
    vector<int> currentSet = {1, 15, 27};
    int featuretoadd = 27;

    vector<Object> data = interpretTxtFile(fileName);

    cout << "Type the number of algorithm you want to run" << endl;
    cout << "1. Forward Selection" << endl;
    cout << "2. Backward Selection" << endl;
    cout << "3. Jonas's Special Algorithm" << endl;

    cin >> algo;

    cout << endl;
    cout << "This dataset has " << data.at(0).getFeatureSize()-1 << " features (Not including the class attribute), with " << data.size() << " instances." << endl;
    cout << endl;
    cout << "Normalizing..." << endl;
    cout << endl;

    cout << "Running nearest neighbor with no features (default rate), using leaving-one-out evaluation, I get an accuracy of " << endl;
    cout << endl;

    if(algo == 1){
        auto start = chrono::system_clock::now();
        ForwardSelection(data);
        auto end = chrono::system_clock::now();
 
        chrono::duration<double> elapsed_seconds = end - start;
        time_t end_time = chrono::system_clock::to_time_t(end);
    
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s"
                << std::endl;

    }
    else if(algo == 2){
        BackwardSelection(data);
    }
    else if(algo == 3){
        // NN(interpretTxtFile());
        // cout << "Accuracy: " << leaveOneOutCrossValidation(interpretTxtFile(), currentSet, featuretoadd);
    }
    return 0;
}