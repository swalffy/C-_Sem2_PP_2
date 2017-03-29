#include <iostream>
using namespace std;
class line {
	char *str;
public:
	line(char *x) {
		cout << "Constructor" << endl;
		str = new char[strlen(x)];
		strcpy(str, x);
	}
	int size() {
		return strlen(str);
	}
	~line() {
		cout << "Destructor" << endl;
		if (str != NULL) {
			delete[] str;
		}
	}
	//cout
	friend ostream& operator<< (ostream &os, line &obj) {
		for (int i = 0; i < obj.size(); i++)
			os << obj.str[i];
		return os;
	}
	//cin
	friend istream& operator>> (istream& is, line& obj) {
		is >> obj.str;

		return is;
	}

	void setData(char* input) {
		str = input;
	}
	line& mergeLine(line& a, line& b) {
		int len = a.size() + b.size() + 1;
		char *temp = new char[len];
		strcpy(temp, a.str);
		strcat(temp, b.str);
		return line(temp);
	}
	line* operator+ (line x) {
		int len = size() + x.size() + 1;
		char *temp = new char[len];
		strcpy(temp, str);
		strcat(temp, x.str);
		line result(temp);
		delete[]temp;
		cout << result << endl;
		return &result;
	}
};

int main() {
	line a("asdasd");
	line b("123123");
	line c("|");
	c.mergeLine(a, b);
	return 0;
}
