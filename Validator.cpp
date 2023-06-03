#include "Validator.h"

using namespace std;

float leaveOneOutCrossValidation(vector<Object> data, vector<int> featureSet, int featuretoAdd){
    int found = 0;
    int index = -1;
    for(int i = 0; i < data.size(); i++){
        vector<float> features = data.at(i).getFeatures();
        for(int j = 0; j < features.size(); j++){
            found = 0;
            index = -1;
            for(int k = 0; k < featureSet.size(); k++){
                if(j == 0){
                    continue;
                }
                if(j == featuretoAdd){
                    continue;
                }
                if(found == 1){
                    continue;
                }
                if(j == featureSet.at(k)){
                    found = 1;
                }
                if(j != featureSet.at(k)){
                    // features.erase(find(features.begin(), features.end(), j));
                    // features.at(j) = 0;
                    if(k == featureSet.size()-1){
                        features.at(j) = 0;
                    }
                }
            }
        }
        data.at(i).setFeatures(features);
    }
    
    return NN(data);
}