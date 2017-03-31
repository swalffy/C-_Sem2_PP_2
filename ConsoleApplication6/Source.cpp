#include <iostream>
using namespace std;
class Line
{
private:
	char *str;
	int len;
public:
	Line() {
		str = NULL;
		len = 0;
	}
	Line(char *x) {
		len = strlen(x) + 1;
		str = new char[len];
		strcpy(str, x);
	}
	int size() {
		return len;
	}
	~Line() {
		delete[]str;
	}
	friend ostream& operator<< (ostream &os, Line &obj) {
		for (int i = 0; i < obj.size(); i++)
			os << obj.str[i];
		return os;
	}
	friend istream& operator>> (istream& is, Line& obj)
	{
		is >> obj.str;
		obj.len = strlen(obj.str) + 1;
		return is;
	}

	void setData(char* input)
	{
		str = input;
		len = strlen(input) + 1;
	}
	Line& mergeLine(Line& a, Line& b)
	{
		a.len += b.len;
		char *temp = new char[a.len];
		strcpy(temp, a.str);
		strcat(temp, b.str);
		Line result(temp);
		delete[]temp;
		cout << result << endl;
		return result;
	}
	Line& operator+ (Line& x)
	{
		
	}
};

int main(int argc, char *argv[]) {
	Line a("Blablabla");
	a.setData("2132165  asdas");
	cout << a << endl;
	Line b;
	Line c;
	b.setData("123");
	c.mergeLine(a, b);
	cin >> a;
	system("pause");
	return 0;
}
