#include <iostream>
#include <string>
using namespace std;
void HextoStr(string& str_,char* hex_)
{
	for (string::size_type ps=0;ps!=str_.size();ps+=2)
	{
		basic_string<char> tmp=str_.substr(ps,2);
		char* s;
		char hex=strtol(tmp.c_str(),&s,0x10);
		memcpy(hex_,&hex,1);
		hex_++;
	}
}

int main()
{
	string s1="333132343536666162bbcae58ebb";
	int len=s1.size()/2+1;
	
	char* ch=new char[len];
	memset(ch,0,len);
	HextoStr(s1,ch);
	cout<<"Êä³ö:\n"<<ch<<endl;
	delete[] ch;
	return 0;
}