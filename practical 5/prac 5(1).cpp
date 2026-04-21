#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main()
{
	fstream obj;
	obj.open("example.txt", ios::out|ios::in);
	string line;
	getline(cin, line);
	obj<<line;
	obj.seekg(0);
	
	int freq[20]={0};//for storing count 
	string word[20];//for storing individual word 
	string current_word="";//for separating word
	char ch;//for character reading
	int flag=0;//for maintaining array count
	while(obj.get(ch))
	{
		if(ch!=' ' && ch!='\n')
		{
			ch=tolower(ch);
			current_word+=ch;
		} else
		{
		    if(current_word != "")
		    {
			int found=-1;
			for(int i=0; i<flag; i++)
			{
				if(word[i]==current_word)
				{
					found=i;
					break;
				}
			}
				if(found!=-1)
				{
					freq[found]++;
				} else
				{
					word[flag]=current_word;
					freq[flag]=1;
					flag++;
				}
				current_word="";//aa bhulto naii bhaii naitar overwrite thse word
			}
		}
	}
	//since the last word is being excluded thats why explicitly include it.
	if(current_word != "")
		    {
			int found=-1;
			for(int i=0; i<flag; i++)
			{
				if(word[i]==current_word)
				{
					found=i;
					break;
				}
			}
				if(found!=-1)
				{
					freq[found]++;
				} else
				{
					word[flag]=current_word;
					freq[flag]=1;
					flag++;
				}
		    }
	
	cout<<"Frequencies are:"<<endl;
	for(int i =0;i<flag;i++)
	{
	     cout<<"Word is : "<<word[i]<<" frequency is "<<freq[i] <<endl;
	}
obj.close();
	return 0;
}