#include "MyString.h"

using namespace std;
class Line {
	char *str;
public:
Line::Line() {
		str = NULL;
	}
Line::Line(char *x) {
		cout << "Constructor" << endl;
		str = new char[strlen(x)];
		strcpy(str, x);
	}
int Line::size() {
		return strlen(str);
	}
Line::~Line() {
		cout << "Destructor" << endl;
		if (str != NULL) {
			//delete str;
		}
	}
	//cout
friend ostream& Line::operator<< (ostream &os, Line &obj) {
		for (int i = 0; i < obj.size(); i++)
			os << obj.str[i];
		return os;
	}
	//cin
friend istream& Line::operator >> (istream &ifs, Line &obj) {
		char* temp = new char[100];
		ifs >> temp;
		int len = strlen(temp)+1;
		delete[] obj.str;
		obj.str = new char[len];
		strcpy(obj.str, temp);
		delete[] temp;
		return ifs;
	}

	void Line::setData(char* input) {
		str = input;
	}
	Line* Line::mergeLine(Line& a, Line& b) {
			int len = a.size() + b.size() + 1;
			char *temp = new char[len];
			strcpy(temp, a.str);
			strcat(temp, b.str);
			Line *result = new Line (temp);
			delete[] temp;
			return result;
	}
	char& Line::operator[](int j) //перегрузка []     
	{
		return str[j];
	}
	Line& Line::operator+ (Line &x) {
		int len = size() + x.size() + 1;
		char *temp = new char[len];
		strcpy(temp, str);
		strcat(temp, x.str);
		Line *result = new Line(temp);
		delete[] temp;
		return *result;
	}
	int Line::find(Line key) {
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == key[0]) {
				int k = 0;
				bool flag = true;
				do {
					if (str[i + k] != key[k]) {
						flag = false;
						break;
					}
					k++;
				} while (k < key.size());
				if (flag) {
					return i;
				}
			}
		}
		return -1;
	}
	Line Line::erase (int cur, int count) {
	/*	int len = strlen(str) - count+1;
		char *temp = new char[len];
		strcpy(temp, "");
		temp[0] = 'a';
		Line *result = new Line(temp);
		delete[] temp;
		return result;*/
		int size = strlen(str) + 1;
		memmove(str + cur, str + cur + count, size  - cur - count);
		return str;
	}
};