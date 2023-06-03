#include "Search.h"

using namespace std;
/*
    Backward Selection Search
*/
void BackwardSelection(vector<Object> tempdata){
    // Initial State = All features
    // Operators: Subtract a feature
    // Eval function: K-Fold but we dont implemetn this in part 1
    vector<Object> data = tempdata;
    vector<int> features;
    vector<int> currentFeatures;
    vector<int> Subbed;
    vector<int> bestFeatures;
    float THEbestAccuracy = 0;
    float bestAccuracy;
    float accuracy = 0;
    int featuretoSub;
    int decreasing = 0;

    for(int i = 1; i < data.at(0).getFeatureSize(); i++){
        features.push_back(i);
    }

    bestFeatures = features;
    currentFeatures = features;

    std::cout << "Beginning Search" << endl;
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
                std::cout << "Using feature(s) {";
                Subbed = currentFeatures;
                if(currentFeatures.size() != 1){
                    if(find(currentFeatures.begin(), currentFeatures.end(), k) != currentFeatures.end()){
                        currentFeatures.erase(find(currentFeatures.begin(), currentFeatures.end(), k));
                    }
                }
                for(int i = 0; i < currentFeatures.size(); i++){
                    if(i == currentFeatures.size()-1){
                        std::cout << currentFeatures.at(i);
                    }
                    else{
                        std::cout << currentFeatures.at(i) << ", ";
                    }
                }
                std::cout << "} accuracy is " << accuracy << "%" << endl;
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
            cout << endl;
            std::cout << "Feature set {";
            for(int i = 0; i < bestFeatures.size(); i++){
                if(i == bestFeatures.size()-1){
                    std::cout << bestFeatures.at(i);
                }
                else{
                    std::cout << bestFeatures.at(i) << ", ";
                }
            }
            std::cout << "} was best, accuracy is " << THEbestAccuracy << "%" << endl;
            cout << endl;
        }
        else if(decreasing == 0){
            std::cout << endl;
            std::cout << "Warning, Accuracy has decreased. Continuing Search..." << endl;
            std::cout << endl;
            decreasing = 1;
        }
    }
    std::cout << endl;
    std::cout << "Finished Search!! The best feature subset is {";
    for(int i = 0; i < bestFeatures.size(); i++){
        if(i == bestFeatures.size()-1){
            std::cout << bestFeatures.at(i);
        }
        else{
            std::cout << bestFeatures.at(i) << ", ";
        }
    }
    std::cout << "} which has an accuracy of " << THEbestAccuracy << "%" << endl;
    std::cout << endl;
}

/*
    Forward Selection Search
*/
void ForwardSelection(vector<Object> tempData){
    // Initial State = no Features
    // Operators: Adda  feature
    // Eval function: K-Fold but we dont implemetn this in part 1
    vector<Object> data = tempData;
    vector<int> features;
    vector<int> currentFeatures;
    vector<int> bestFeatures;
    float THEbestAccuracy = 0;
    float bestAccuracy;
    float accuracy = 0;
    int featuretoAdd;
    int decreasing = 0;

    for(int i = 1; i < data.at(0).getFeatureSize(); i++){
        features.push_back(i);
    }

    std::cout << "Beginning Search" << endl;
    for(int i = 0; i < features.size(); i++){
        bestAccuracy = 0;
        for(int j = 0; j < features.size(); j++){
            // if returns true then dont add
            if(checkDuplicate(features.at(j), currentFeatures) == false){
                // Currently Random (1 - 100)
                accuracy = leaveOneOutCrossValidation(data, currentFeatures, featuretoAdd);
                //Beginning of Trace
                std::cout << "Using feature(s) {";
                if(currentFeatures.empty()){
                    std::cout << j;
                }
                else{
                    std::cout << j << ", ";
                }
                for(int i = 0; i < currentFeatures.size(); i++){
                    if(i == currentFeatures.size()-1){
                        std::cout << currentFeatures.at(i);
                    }
                    else{
                        std::cout << currentFeatures.at(i) << ", ";
                    }
                }
                std::cout << "} accuracy is " << accuracy << "%" << endl;
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
            std::cout << endl;
            std::cout << "Feature set {";
            printbestFeatures(bestFeatures);
            std::cout << "} was best, accuracy is " << THEbestAccuracy << "%" << endl;
            std::cout << endl;
        }
        if(bestAccuracy < THEbestAccuracy && decreasing == 0){
            std::cout << endl;
            std::cout << "Warning, Accuracy has decreased. Continuing Search..." << endl;
            std::cout << endl;
            decreasing = 1;
        }
    }
    std::cout << endl;
    std::cout << "Finished Search!! The best feature subset is {";
    printbestFeatures(bestFeatures);
    std::cout << "} which has an accuracy of " << THEbestAccuracy << "%" << endl;
    std::cout << endl;
}

