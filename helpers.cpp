#include "helpers.h"

using namespace std;

vector<Object> interpretTxtFile(string fileName){
    string myText;
    vector<Object> data;

    ifstream myReadFile(fileName);
    // ifstream myReadFile("large-test-dataset-1.txt");

    while(getline(myReadFile, myText)){
        Object temp;
        int Class;
        vector<float> features;

        stringstream linestream(myText);
        string text;

        temp.setClass(stoi(myText));
        while (linestream >> text){
            temp.appendFeature(stof(text));
        }

        data.push_back(temp);
    }

    myReadFile.close();

    // for(int i = 0; i < data.size(); i++){
    //     cout << "Row/Object " << i+1 << ": ";
    //     data.at(i).print();
    // }

    return data;
}

float Euclidean(vector<float> data, vector<float> data2){
    float distance;
    for(int i = 0; i < data.size(); i++){
        // Basically excludes first column which are class labels(1 or 2) and the excluded features(0)
        if(data.at(i) == 0 || data2.at(i) == 0 ||
        data.at(i) == 1 || data2.at(i) == 1 ||
        data.at(i) == 2 || data2.at(i) == 2){
            continue;
        }
        // cout << "data: " << data.at(i) << " - data2: " << data2.at(i) << endl;
        distance += pow(data.at(i) - data2.at(i), 2);
    }
    return sqrt(distance);
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
void printbestFeatures(vector<int> bestFeatures){
    for(int i = 0; i < bestFeatures.size(); i++){
        if(i == bestFeatures.size()-1){
            std::cout << bestFeatures.at(i);
        }
        else{
            std::cout << bestFeatures.at(i) << ", ";
        }
    }
}