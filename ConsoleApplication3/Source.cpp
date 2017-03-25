#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
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
string lineProcessing(string line)
{
	for (std::string::iterator i = line.begin(); i != line.end(); ++i)
	{

		if (ispunct(*i) && (*i) != '\'' && (*i) != '’' && (*i) != '-')
		{
			*i = ' ';
		}
		if (isprint(*i))
		{
			*i = char(tolower(*i));
		}
		i--;
	}
	return line;
}
void dictionarySorting(int l, int r, vector <myMap> &input)
{
	int x = input[l + (r - l) / 2].key.size();
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (input[i].key.size() > x) i++;
		while (input[j].key.size() < x) j--;
		if (i <= j)
		{
			swap(input[i], input[j]);
			i++;
			j--;
		}
	}
	if (i < r)
		dictionarySorting(i, r, input);

	if (l < j)
		dictionarySorting(l, j, input);
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
			value.key = key ;
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
answer getEmotionalSum(vector<myMap> dictionary, vector<string> text)
{
	answer result = { 0.0,0 };
	for (int i = 0; i < dictionary.size(); i++)
	{
		for (int j = 0; j < text.size(); j++)
		{
			size_t pos;
			do
			{
				pos = text[j].find(' ' + dictionary[i].key + ' ');
				if (pos != std::string::npos)
				{
					std::cout << dictionary[i].key << " |" << dictionary[i].value << "| " << text[j] << "\n";
					text[j].erase(pos+1, dictionary[i].key.size());
					text[j][pos] = '&' ;
					result.count++;
					result.weight += dictionary[i].value;
				}
			} while (pos != std::string::npos);
		}
	}
	cout << endl;
	return result;
}
int main()
{
	string fileName;
	vector<myMap> mapOfWeight;
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