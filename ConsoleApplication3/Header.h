#ifndef libs
#define libs
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#endif

using namespace std;
#ifndef structs
#define structs
struct myMap
{
	string key;
	double value;
};
struct answer
{
	double weight;
	int count;
};

#endif

#ifndef inputLib
#define inputLib

vector <string> getTextFromFile(string fileName);
vector <string> getLinesFromFile(string fileName);
vector <myMap> getDictionary(string fileName);
#endif

#ifndef processingFunctions
#define processingFunctions
string lineProcessing(string line);
void dictionarySorting(int l, int r, vector <myMap> &input);
answer getEmotionalSum(vector<myMap> dictionary, vector<string> text);
#endif 
