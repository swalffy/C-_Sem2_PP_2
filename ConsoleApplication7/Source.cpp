#include <iostream>

using namespace std;
class Line {
	char *str;
public:
	Line() {
		str = NULL;
	}
	Line(char *x) {
		cout << "Constructor" << endl;
		str = new char[strlen(x)];
		strcpy(str, x);
	}
	int size() {
		return strlen(str);
	}
	~Line() {
		cout << "Destructor" << endl;
		if (str != NULL) {
			//delete str;
		}
	}
	//cout
	friend ostream& operator<< (ostream &os, Line &obj) {
		for (int i = 0; i < obj.size(); i++)
			os << obj.str[i];
		return os;
	}
	//cin
	friend istream& operator >> (istream &ifs, Line &obj) {
		char* temp = new char[100];
		ifs >> temp;
		int len = strlen(temp)+1;
		delete[] obj.str;
		obj.str = new char[len];
		strcpy(obj.str, temp);
		delete[] temp;
		return ifs;
	}

	void setData(char* input) {
		str = input;
	}
	Line* mergeLine(Line& a, Line& b) {
			int len = a.size() + b.size() + 1;
			char *temp = new char[len];
			strcpy(temp, a.str);
			strcat(temp, b.str);
			Line *result = new Line (temp);
			delete[] temp;
			return result;
	}
	char& operator[](int j) //���������� []     
	{
		return str[j];
	}
	Line& operator+ (Line &x) {
		int len = size() + x.size() + 1;
		char *temp = new char[len];
		strcpy(temp, str);
		strcat(temp, x.str);
		Line *result = new Line(temp);
		delete[] temp;
		return *result;
	}
	int find(Line key) {
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
	Line erase (int cur, int count) {
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

int main() {
	Line a("asdasd");
	string f;
	Line b("12||3123");
	Line c;
   cin >> c;

	cout << b.erase(2,2);
	cout << c.size();
	return 0;
}