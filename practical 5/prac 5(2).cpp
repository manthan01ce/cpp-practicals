#include<sstream>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream obj;
	obj.open("example.txt", ios::out);
	string line;
	getline(cin,line);
	obj<<line;
	obj.clear();
	obj.seekg(0);//dar vkhte bhuli jas manthanyaa
	obj.close();
	obj.open("example.txt",ios::in);
	char ch;
	string temp;
	string word="";
	int count_word=0;
	int count_line=0;
	int count_vowel=0;
	int count_space=0;
	int count_character=0;
	while(getline(obj,temp))//line read kairi hve word by word read krva mte stringstream.
	{
		count_line++;
		stringstream ss(temp);
		string token;
		while(ss>>token)
		{
			count_space++;
			count_character++;
			count_word++;
			string s=token;
			for(int i =0; i<token.length(); i++)
			{
				count_character++;
				if(s[i]=='a'|| s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
				{
					count_vowel++;
				}
			}
		}
	}
	obj.close();
	cout<<"The countings are "<<endl;
	cout<<"The word count is "<<count_word<<endl;
	cout<<"The line count is "<<count_line<<endl;
	cout<<"The vowel count is "<<count_vowel<<endl;
	cout<<"The character count is "<<count_character-1<<endl;
	cout<<"The number of spaces are "<<count_space<<endl;
	cout<<"The number of the consonants are "<<(count_character-count_vowel)-1<<endl;

	return 0;
}