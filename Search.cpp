#include "Search.h"

using namespace std;
/*
    Backward Selection Search
*/
void BackwardSelection(vector<int> features){
    // Initial State = All features
    // Operators: Subtract a feature
    // Eval function: K-Fold but we dont implemetn this in part 1
    vector<Object> data = interpretTxtFile();
    vector<int> currentFeatures;
    vector<vector<int>> tempsubFeatures;
    vector<int> Subbed;
    vector<int> bestFeatures;
    float THEbestAccuracy = 0;
    float bestAccuracy;
    float accuracy = 0;
    int featuretoSub;
    int decreasing = 0;

    bestFeatures = features;
    currentFeatures = features;

    cout << "Beginning Search" << endl;
    for(int i = 0; i < features.size(); i++){
        int k = 0;
        bestAccuracy = 0;
        for(int j = 0; j < features.size(); j++){
            // if returns true then SUBTRACT cuz idk??
            if(checkDuplicate(features.at(j), currentFeatures) == true){
                // Currently Random (1 - 100)
                accuracy = leaveOneOutCrossValidation(data, currentFeatures, featuretoSub);
                /*
                    Beginning of Trace
                */
                cout << "Using feature(s) {";
                Subbed = currentFeatures;
                if(currentFeatures.size() != 1){
                currentFeatures.erase(find(currentFeatures.begin(), currentFeatures.end(), k));
                }
                for(int i = 0; i < currentFeatures.size(); i++){
                    if(i == currentFeatures.size()-1){
                        cout << currentFeatures.at(i);
                    }
                    else{
                        cout << currentFeatures.at(i) << ", ";
                    }
                }
                cout << "} accuracy is " << accuracy << "%" << endl;
                currentFeatures = Subbed;
                /*
                    End of Trace
                */
                if(accuracy > bestAccuracy){
                    bestAccuracy = accuracy;
                    featuretoSub = features.at(j);
                }
            }
            k++;
        }
        //Erases the featuretoSub
        currentFeatures.erase(find(currentFeatures.begin(), currentFeatures.end(),featuretoSub));
        if(bestAccuracy > THEbestAccuracy){
            THEbestAccuracy = bestAccuracy;
            bestFeatures = currentFeatures;
            cout << "Feature set {";
            for(int i = 0; i < bestFeatures.size(); i++){
                if(i == bestFeatures.size()-1){
                    cout << bestFeatures.at(i);
                }
                else{
                    cout << bestFeatures.at(i) << ", ";
                }
            }
            cout << "} was best, accuracy is " << THEbestAccuracy << "%" << endl;
        }
        else if(decreasing == 0){
            cout << endl;
            cout << "Warning, Accuracy has decreased. Continuing Search..." << endl;
            cout << endl;
            decreasing = 1;
        }
    }
    cout << endl;
    cout << "Finished Search!! The best feature subset is {";
    for(int i = 0; i < bestFeatures.size(); i++){
        if(i == bestFeatures.size()-1){
            cout << bestFeatures.at(i);
        }
        else{
            cout << bestFeatures.at(i) << ", ";
        }
    }
    cout << "} which has an accuracy of " << THEbestAccuracy << "%" << endl;
    cout << endl;
}

/*
    Forward Selection Search
*/
void ForwardSelection(vector<int> features){
    // Initial State = no Features
    // Operators: Adda  feature
    // Eval function: K-Fold but we dont implemetn this in part 1
    vector<Object> data = interpretTxtFile();
    vector<int> currentFeatures;
    vector<int> bestFeatures;
    float THEbestAccuracy = 0;
    float bestAccuracy;
    float accuracy = 0;
    int featuretoAdd;
    int decreasing = 0;

    cout << "Beginning Search" << endl;
    for(int i = 0; i < features.size(); i++){
        bestAccuracy = 0;
        for(int j = 0; j < features.size(); j++){
            // if returns true then dont add
            if(checkDuplicate(features.at(j), currentFeatures) == false){
                // Currently Random (1 - 100)
                accuracy = leaveOneOutCrossValidation(data, currentFeatures, featuretoAdd);
                //Beginning of Trace
                cout << "Using feature(s) {";
                if(currentFeatures.empty()){
                    cout << j;
                }
                else{
                    cout << j << ", ";
                }
                for(int i = 0; i < currentFeatures.size(); i++){
                    if(i == currentFeatures.size()-1){
                        cout << currentFeatures.at(i);
                    }
                    else{
                        cout << currentFeatures.at(i) << ", ";
                    }
                }
                cout << "} accuracy is " << accuracy << "%" << endl;
                //End of Trace
                if(accuracy > bestAccuracy){
                    bestAccuracy = accuracy;
                    featuretoAdd = features.at(j);
                }
            }
        }
        currentFeatures.push_back(featuretoAdd);
        if(bestAccuracy > THEbestAccuracy){
            THEbestAccuracy = bestAccuracy;
            bestFeatures = currentFeatures;
            cout << "Feature set {";
            for(int i = 0; i < bestFeatures.size(); i++){
                if(i == bestFeatures.size()-1){
                    cout << bestFeatures.at(i);
                }
                else{
                    cout << bestFeatures.at(i) << ", ";
                }
            }
            cout << "} was best, accuracy is " << THEbestAccuracy << "%" << endl;
        }
        else if(decreasing == 0){
            cout << endl;
            cout << "Warning, Accuracy has decreased. Continuing Search..." << endl;
            cout << endl;
            decreasing = 1;
        }
    }
    cout << endl;
    cout << "Finished Search!! The best feature subset is {";
    for(int i = 0; i < bestFeatures.size(); i++){
        if(i == bestFeatures.size()-1){
            cout << bestFeatures.at(i);
        }
        else{
            cout << bestFeatures.at(i) << ", ";
        }
    }
    cout << "} which has an accuracy of " << THEbestAccuracy << "%" << endl;
    cout << endl;
}

