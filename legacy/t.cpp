#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int m;
	cin >> m;
	cout << m<<"\n";
	string s;
	cin >> s;
	cout << s<<"\n";
	getline(cin,s);
	printf("im text with %s\n",s.c_str());
	return 0;
}
