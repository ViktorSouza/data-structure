#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<char> brackets;
	string str;
	string open_brackets = "[{(";
	string close_brackets = "]})";
	cout << "Enter the string"<<endl;
	cin >> str;
	bool isValid = true;

	for (char &s: str){
		// If the char is ), ] or }
		if(close_brackets.find(s) != string::npos){
			if((brackets.size() == 0)|| (close_brackets.find(s) != open_brackets.find(brackets.top()))){
				isValid = false;
				break;
			}

			brackets.pop();
		}
		// Case (, [ or {
		else{
			brackets.push(s);
		}

	}

	
	if(brackets.size()>0){
		isValid = false;
	}

	cout<< isValid<<endl;

	return 0;
}

