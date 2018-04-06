#include<iostream>
#include<string.h>
using namespace std;
bool check_balanced(char []);
class stack1{
	char *s;
   int size, top;
public:
	stack1()
	{
		s=NULL;
		size=0;
		top= -1;
	}
	~stack1()
	{
		delete s;
//		cout<<"in delete = "<<s;
		size=0;
		top= -1;
	}

	void get_size(int);
	void push(char);
	char pop();
	char peak();
	bool isFull();
	bool isEmpty();
	void display();
};
void stack1::get_size(int n){
	s= new char[n];
	size= n;
}
void stack1::push(char element){
	if(!isFull()){
		s[++top]= element;
//		cout<<"\nElement pushed in stack : "<<s[top]<<endl;
	}else{
		cout<<" stack is full\n";
	}
}
char stack1::pop(){
	char x = -99;

	if(!isEmpty()){
		x= s[top--];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}
char stack1::peak(){
	char x = -99;
	if(!isEmpty()){
		x= s[top];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}
bool stack1::isFull(){
	return(size-1 == top);
}
bool stack1::isEmpty(){
	return(top==-1);
}
void stack1::display(){
	int i;
	for(i=0;i<=top;i++){
		cout<<"\n "<<s[i];
	}
}
int main(){
	stack1 s1;
	char str[25]= "a*[b+c+(d+e)]";
	cout<<"str : "<<str<<endl;
	bool b;
	b = check_balanced(str);
	cout<<"\n b :"<<b;

	return(0);
}
bool check_balanced(char str[25]){
	stack1 s1;
	int flag =0;
	int n,i;
	char ch,pch;
	n = strlen(str);
	s1.get_size(n);
	for (i = 0; i < n; i++) {
		ch = str[i];
		switch (ch) {
			case '(':
			case '[':
			case '{':
				s1.push(ch);
				break;
			case '}':
			case ']':
			case ')':
				if (!s1.isEmpty()) {
					pch= s1.peak();
					if( (pch=='('&&ch==')')||(pch=='['&&ch==']')||(pch=='{'&&ch=='}')) {
						pch = s1.pop();
						cout<<"\nExpression mached '"<<pch<<"' with '"<<ch<<"'\n";
					}else{
						flag =1;
						break;
					}
				}
				defult: ;
		}// switch closing
		if(flag==1){
			break;// for loop is break
		}
	}//for loop closing

if (s1.isEmpty()&&i==strlen(str)) {
	cout << "String is balanced" << '\n';
	return true;
} else {
	cout << "String is not balanced" << '\n';
	return false;
}
}
