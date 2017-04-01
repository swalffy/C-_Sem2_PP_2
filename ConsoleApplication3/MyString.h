#ifndef libs
#define libs
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#endif
class Line {
	char *str;
public:
	Line();
	Line(char *x);
	int size();
	~Line();
	friend ostream& operator<< (ostream &os, Line &obj);
	friend istream& operator >> (istream &ifs, Line &obj);
	void setData(char* input);
	Line* mergeLine(Line& a, Line& b);
	char& operator[](int j);
	Line& operator+ (Line &x);
	int find(Line key);
	Line erase(int cur, int count);
};