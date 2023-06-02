#include "helpers.h"

using namespace std;

vector<Object> interpretTxtFile(){
    string myText;
    string temp1 = "3.3396418e-001";
    float temp;
    vector<Object> data;

    ifstream myReadFile("small-test-dataset.txt");
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
        if(data.at(i) == 0 || data2.at(i) == 0){
            continue;
        }
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