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
bool checkInput(string s)
{
	string grade[5] = {"A","B","C","D","F"};
	for(int i=0;i<5;i++) {
		if(s == grade[i]) return true;
	}
	return false;
}
void makeLine()
{
		for(int i=0;i<30;i++) cout <<"-";
		cout << "\n";
}
string Upper(string s)
{
	string s_new;
	for(int i=0;i<s.size();i++) {
		s_new += toupper(s[i]);
	}
	return s_new;
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
	getline(cin,s); //? s = score A, s = name sanji, s = exit
	int idx = s.find_first_of(" "); //TODO find NAME,EXIT,SCORE
	string s1 = Upper(s.substr(0,idx)); //Command: name,grade,exit
	string s2 = Upper(s.substr(idx+1,s.size())); //Option: a,b,c,...,Sanji
	
	if(s1 == "NAME")
	{
		bool checkFound = false;
		for(int i=0;i<v_name.size();i++)
		{
			if(s2 == Upper(v_name[i])){
				makeLine();
				cout << v_name[i] << "'s grade = " << v_grade[i] <<"\n";
				checkFound = true;
			}
		}
		if(checkFound == false) cout << "Cannot found.\n";
		else makeLine();
	}
	else if(s1 == "GRADE")
	{
		bool check = checkInput(Upper(s2));
		if(check == true){
			makeLine();
			for(int i=0;i<v_name.size();i++)
			{
				if(Upper(s2) == Upper(v_grade[i]))
					cout << v_name[i] << "\n";
			}
			makeLine();
		}
		else cout << "Cannot found.\n";
	}
	else if(s1 == "EXIT") break;
	else cout << "Invalid command.\n"; 
	}
}


