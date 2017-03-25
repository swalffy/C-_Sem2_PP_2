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
#ifndef structures
#define structures
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

#ifndef inputFunctions
#define inputFunctions

vector <string> getTextFromFile(string);
vector <string> getLinesFromFile(string);
vector <myMap> getDictionary(string);
#endif

#ifndef processingFunctions
#define processingFunctions
bool isSepareted(string, int, string);
string lineProcessing(string);
void dictionarySorting(int, int, vector <myMap> &);
answer getEmotionalSum(vector<myMap>, vector<string>);
#endif 
