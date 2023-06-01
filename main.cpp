#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int leaveOneOutCrossValidation(){
    return rand() % 100;
}

bool checkDuplicate(int feature, vector<int> addedFeatures){
    for(int i = 0; i < addedFeatures.size(); i++){
        if(feature == addedFeatures.at(i)){
            return true;
        }
    }
    // False if no duplicate
    return false;
}

/*
    Backward Selection Search
*/
void BackwardSelection(vector<int> features){
    // Initial State = All features
    // Operators: Subtract a  feature
    // Eval function: K-Fold but we dont implemetn this in part 1
    vector<int> currentFeatures;
    vector<vector<int>> tempsubFeatures;
    vector<int> Subbed;
    vector<int> bestFeatures;
    int THEbestAccuracy = 0;
    int bestAccuracy;
    int accuracy = 0;
    int featuretoSub;

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
                accuracy = leaveOneOutCrossValidation();
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
        else{
            cout << "Warning, Accuracy has decreased" << endl;
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
        }
    }
}

/*
    Forward Selection Search
*/
void ForwardSelection(vector<int> features){
    // Initial State = no Features
    // Operators: Adda  feature
    // Eval function: K-Fold but we dont implemetn this in part 1
    vector<int> currentFeatures;
    vector<int> bestFeatures;
    int THEbestAccuracy = 0;
    int bestAccuracy;
    int accuracy = 0;
    int featuretoAdd;

    cout << "Beginning Search" << endl;
    for(int i = 0; i < features.size(); i++){
        bestAccuracy = 0;
        for(int j = 0; j < features.size(); j++){
            // if returns true then dont add
            if(checkDuplicate(features.at(j), currentFeatures) == false){
                // Currently Random (1 - 100)
                accuracy = leaveOneOutCrossValidation();
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
        else{
            cout << "Warning, Accuracy has decreased" << endl;
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
        }
    }
}

int main(){
    int numofFeatures;
    int algo;
    vector<int> features;
    cout << "Welcome to Jonas Tan's Feature Selection Algorithm" << endl;
    cout << "Please Enter number of features: ";
    cin >> numofFeatures;

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

    }
    return 0;
}