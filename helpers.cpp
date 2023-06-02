#include "helpers.h"

using namespace std;

vector<Object> interpretTxtFile(){
    string myText;
    string temp1 = "3.3396418e-001";
    float temp;
    vector<Object> data;

    ifstream myReadFile("small-test-dataset.txt");

    while(getline(myReadFile, myText)){
        Object temp;
        vector<float> features;

        stringstream linestream(myText);
        string text;

        while (linestream >> text){
            temp.appendFeature(stof(text));
        }
        data.push_back(temp);
    }
    

    cout << data.size() << endl;
    cout << stof(temp1) << endl;

    myReadFile.close();

    return data;
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