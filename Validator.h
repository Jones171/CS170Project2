#ifndef VALIDATOR_H_
#define VALIDATOR_H_

#include "headers.h"
#include "Object.h"
#include "Classifier.h"

using namespace std;

float leaveOneOutCrossValidation(vector<Object>, vector<int>, int);

#endif