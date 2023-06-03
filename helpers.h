#ifndef HELPERS_H
#define HELPERS_H

#include "headers.h"
#include "Object.h"

using namespace std;

vector<Object> interpretTxtFile();
float Euclidean(vector<float>, vector<float>);
bool checkDuplicate(int, vector<int>);
void printbestFeatures(vector<int>);

#endif