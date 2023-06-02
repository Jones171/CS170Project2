#include "helpers.h"

using namespace std;

bool checkDuplicate(int feature, vector<int> addedFeatures){
    for(int i = 0; i < addedFeatures.size(); i++){
        if(feature == addedFeatures.at(i)){
            return true;
        }
    }
    // False if no duplicate
    return false;
}