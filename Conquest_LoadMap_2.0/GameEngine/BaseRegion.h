#ifndef BASEREGION_H
#define BASEREGION_H
#include <string>

using namespace std;

class BaseRegion 
{
	private:
		string baseName;

	public:
		// Public constructor
		BaseRegion(string name);

		// Public methods
		void PrintBaseName();

		// Public vars
		string getBaseName();

};
#endif