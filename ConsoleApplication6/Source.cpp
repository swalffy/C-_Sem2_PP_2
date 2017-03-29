#include <iostream>
using namespace std;
class line
{
private:
	char *str;
	int len;
public:
	line() {
		str = NULL;
		len = 0;
	}
	line(char *x) {
		len = strlen(x) + 1;
		str = new char[len];
		strcpy(str, x);
	}
	int size() {
		return len;
	}
	~line() {
		delete[]str;
	}
	friend ostream& operator<< (ostream &os, line &obj) {
		for (int i = 0; i < obj.size(); i++)
			os << obj.str[i];
		return os;
	}
	friend istream& operator>> (istream& is, line& obj)
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
	line& mergeLine(line& a, line& b)
	{
		a.len += b.len;
		char *temp = new char[a.len];
		strcpy(temp, a.str);
		strcat(temp, b.str);
		line result(temp);
		delete[]temp;
		cout << result << endl;
		return result;
	}
	line& operator+ (line& x)
	{
		
	}
};

int main(int argc, char *argv[]) {
	line a("Blablabla");
	a.setData("2132165  asdas");
	cout << a << endl;
	line b;
	line c;
	b.setData("123");
	c.mergeLine(a, b);
	cin >> a;
	system("pause");
	return 0;
}
