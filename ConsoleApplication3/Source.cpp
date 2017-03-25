#include "Header.h"
using namespace std;

int main()
{
	string fileName;
	vector <myMap> mapOfWeight;
	vector <string> vectorOfWords;
	cout << "-->Input Dictionary File Name: ";
	//cin >> fileName;
	fileName = "testweight";
	fileName += ".txt";
	mapOfWeight = getDictionary(fileName);
	cout << "-->Input Text File Name: ";
	//cin >> fileName;
	fileName = "testtext";
	fileName += ".txt";
	cout << endl << endl;
	vectorOfWords = getLinesFromFile(fileName);
	answer result = getEmotionalSum(mapOfWeight, vectorOfWords);
	cout << "Total sum: " << result.weight << endl;
	cout << "Average sum: " << result.weight / result.count << endl;
	system("pause");
	return 0;
}