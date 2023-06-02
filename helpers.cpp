#include "helpers.h"

using namespace std;

vector<float> interpretTxtFile(){
    string myText;
    string temp1 = "3.3396418e-001";
    float temp;
    vector<float> data; 

    ifstream myReadFile("small-test-dataset.txt");

    while(getline(myReadFile, myText)){
        temp = stof(myText);
        data.push_back(temp);
        stringstream linestream(myText);
        string text;
        while (linestream >> text){
            data.push_back(stof(text));
        }
    }

    for(int i = 0; i < data.size(); i++){
        // gets rid of the class label column
        // Leaves only data
        if(data.at(i) == 1 || data.at(i) == 2){
            data.erase(find(data.begin(), data.end(), data.at(i)));
        }
        cout << data.at(i) << ", ";
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