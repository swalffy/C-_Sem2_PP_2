#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
using namespace std;
string lineProcessing(string line);
vector <string> getTextFromFile(string fileName);
map <string, double> getDictionary(string fileName);
double getEmotionalSum(map<string, double> dictionary, vector<string> text);

int main()
{
	map<string, double> mapOfWeight;
	string fileName;
	vector <string> vectorOfWords;
	cout << "-->Input Dictionary File Name: ";
	cin >> fileName;
	mapOfWeight = getDictionary(fileName);
	cout << "-->Input Text File Name: ";
	cin >> fileName;
	vectorOfWords = getTextFromFile(fileName);
	cout << "Emotional color: " << getEmotionalSum(mapOfWeight, vectorOfWords) << endl;
	system("pause");
	return 0;
}
string lineProcessing(string line)
{
	/*if (line == "And feed me with a shepherd's care;")
	{
	int k = 1;
	}*/
	for (std::string::iterator i = line.begin(); i != line.end(); ++i)
	{
		/*if (line == "And feed me with a shepherd's care;")
		{
		int k = 2;
		cout << line[27];
		}*/
		if (ispunct(*i) && (*i) != '\'' && (*i) != '’')
		{
			*i = ' ';
		}
		if (isprint(*i))
		{
			*i = char(tolower(*i));
		}
	}
	return line;
}
vector <string> getTextFromFile(string fileName)
{
	ifstream ifs;
	vector <string> vectorResult;
	ifs.open(fileName);
	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			string temp;
			getline(ifs, temp);
			temp = lineProcessing(temp);
			//cout << temp << endl;
			stringstream s(temp);
			for (string word; s >> word; vectorResult.push_back(word));
		}
		ifs.close();
	}
	return vectorResult;
}
map <string, double> getDictionary(string fileName)
{
	ifstream ifs;
	map <string, double> mapResult;
	ifs.open(fileName);
	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			string temp;
			getline(ifs, temp);
			for (std::string::iterator i = temp.begin(); i != temp.end(); ++i)
			{
				if (
					(*i) == ','
					|| (*i) == ':'
					|| (*i) == '\"'
					|| (*i) == '#'
					|| (*i) == '@'
					)
				{
					*i = '|';
				}
			}
			stringstream s(temp);
			string key, weight;
			getline(s, key, '|');
			s >> weight;
			mapResult.emplace(key, stod(weight));
		}
		cout << ">Dictionary reading was ended. Continue." << endl;
		ifs.close();
	}
	return mapResult;
}
double getEmotionalSum(map<string, double> dictionary, vector<string> text)
{
	double sum = 0.0;
	int count = 0;
	for (int i = 0; i < text.size(); i++)
	{

		map<string, double>::iterator tempMap = dictionary.find(text[i]);
		if (tempMap == dictionary.end())
		{
			count++;
			continue;
		}
		cout << i << setw(10) << tempMap->first << setw(5) << "|" << setw(9) << tempMap->second << endl;
		sum += tempMap->second;
	}
	cout << "=====" << endl;
	cout << count << endl;
	cout << endl;
	return sum;
}