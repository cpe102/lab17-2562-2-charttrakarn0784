#include<iostream>
#include<vector>
#include<fstream>
#include<cctype>
#include<string>
#include<cstring>
using namespace std;
string checkGrade(int g)
{
	if(g >= 80) return "A";
	else if(g >= 70) return "B";
	else if(g >= 60) return "C";
	else if(g >= 50) return "D";
	else return "F";
}
void makeLine()
	{
		for(int i=0;i<20;i++) cout <<"-";
		cout << "\n";
	}
int main() {
	vector<string> v_name,v_grade;
	ifstream f("name_score.txt");
	string s;
	char name[100];
	int num1,num2,num3;
	while (getline(f,s))
	{
		sscanf(s.c_str(),"%[^:]: %d %d %d",name,&num1,&num2,&num3);
		v_name.push_back(name);
		int total = num1+num2+num3;
		v_grade.push_back(checkGrade(total));
	}
while(true){
	cout << "Please input your command: ";
	getline(cin,s);
	int idx = s.find_first_of(" ");
	string s1 = upper( s.substr(0,idx) ); //Command: name,grade,exit
	string s2 = upper( s.substr(idx+1,s.size())); //Option: a,b,c,...,Sanji
	if(s1 == "NAME")
	{
		for(int i=0;i<v_name.size();i++)
		{
			if(s2 == upper(v_name[i]))
				cout << v_name[i] << "'s grade = " << v_grade[i] <<"\n";
		}
		makeLine();
	}
	else if(s1 == "GRADE")
	{
		
	}
	else if(s1 == "EXIT") break;
	else cout << "Invalid command."; 
	}
}


