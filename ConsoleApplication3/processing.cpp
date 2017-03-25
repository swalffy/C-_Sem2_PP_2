#include "Header.h"
using namespace std;

bool isSepareted(string line,int pos, string word)
{
	if ((pos == 0 && (line[pos + word.size()] == ' ' || line[pos + word.size()] == NULL)) ||
		(pos != 0 && line[pos - 1] == ' ' && (line[pos + word.size()] == ' ' || line[pos + word.size()] == NULL)))
	{
		return true;
	}
	return false;
}

string lineProcessing(string line)
{
	bool flag = false;
	int curPos = -1;
	for (std::string::iterator i = line.begin(); i != line.end(); ++i)
	{
		curPos++;
		if ((*i) == ' ')
		{
			if (flag)
			{
				line.erase(curPos, 1);
				i--;
				curPos--;
			}
			flag = true;
			continue;
		}
		if (ispunct(*i) && (*i) != '\'' && (*i) != '’' && (*i) != '-')
		{
		flag = false;
		*i = ' ';
		}
		if (isprint(*i))
		{
			flag = false;
			*i = char(tolower(*i));
		}

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

answer getEmotionalSum(vector<myMap> dictionary, vector<string> text)
{
	answer result = { 0.0,0 };
	for (int i = 0; i < dictionary.size(); i++)
	{
		for (int j = 0; j < text.size(); j++)
		{
			size_t pos;
			pos = text[j].find(dictionary[i].key);
			do
			{
				
				if (pos != std::string::npos && isSepareted(text[j],pos,dictionary[i].key))
				{
					cout <<left<< setw(15)<< dictionary[i].key <<setw(8) <<dictionary[i].value << text[j] << "\n";
					text[j].erase(pos+1 , dictionary[i].key.size());
					text[j][pos] = ' ';
					result.count++;
					result.weight += dictionary[i].value;
					
				}
				pos = text[j].find(dictionary[i].key, pos+1);
			} while (pos != std::string::npos);
		}
	}
	cout << endl;
	return result;
}