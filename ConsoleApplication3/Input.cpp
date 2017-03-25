#include "Header.h"
using namespace std;

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
			stringstream s(temp);
			for (string word; s >> word; vectorResult.push_back(word));
		}
		ifs.close();
	}
	return vectorResult;
}

vector <string> getLinesFromFile(string fileName)
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
			if (temp != "" && temp != " ")
			{
				temp = lineProcessing(temp);
				vectorResult.push_back(temp);
			}
		}
		ifs.close();
	}
	return vectorResult;
}

vector <myMap> getDictionary(string fileName)
{
	ifstream ifs;
	vector <myMap> result;
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
			myMap value;
			value.key = key;
			value.value = stod(weight);
			result.push_back(value);
		}
		cout << ">Dictionary reading was ended. Continue." << endl;
		ifs.close();
	}
	else
	{
		cout << ">Error of reading" << endl;
	}
	dictionarySorting(0, result.size() - 1, result);
	return result;
}