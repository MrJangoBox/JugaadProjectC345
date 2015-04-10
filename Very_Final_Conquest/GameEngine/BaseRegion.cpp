#include "BaseRegion.h"
#include <iostream>
#include <vector>

using namespace std;

//Constructor
BaseRegion:: BaseRegion(string name) {
	baseName = name;
}

string BaseRegion:: getBaseName() {
	return baseName;
}

void BaseRegion::PrintBaseName() {
	cout << baseName << " | " ;
}