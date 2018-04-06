#include<iostream>
#include<string.h>
using namespace std;
int precidence(char);
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
	void push(int);
	int pop();
	char peak();
	bool isFull();
	bool isEmpty();
	void display();
};
void stack1::get_size(int n){
	s= new char[n];
	size= n;
}
void stack1::push(int element){
	if(!isFull()){
		s[++top]= element;
		cout<<"\nElement pushed in stack : "<<element<<endl;
	}else{
		cout<<" stack is full\n";
	}
}
int stack1::pop(){
	int x = -1;

	if(!isEmpty()){
		x= s[top--];
	}else{
		// cout<<"Satck is empty";
	}
	std::cout << "poped value : "<< x << '\n';
	return (x);
}
/*char stack1::peak(){
	char x = -1;
	if(!isEmpty()){
		x= s[top];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}*/
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
	char str[]="123*+";// 1+2*3
	int n = strlen(str);
	int a,b,i,c;
	char ch;
	s1.get_size(n);
  for (i = 0; i < n; i++)
	{
			ch = str[i];
			switch (ch) {
				case '+':
						a= s1.pop(); //type casting char to int
						b =s1.pop(); //type casting char to int
						std::cout << "a : "<< a << '\n';
						std::cout << "b : "<< b << '\n';
						c = b+a;
						s1.push(c);
						break;
				case '-':
						a= s1.pop(); //type casting char to int
						b =s1.pop(); //type casting char to int
						c = b-a;
						s1.push(c);
						break;
				case '*':
						a= s1.pop(); //type casting char to int
						b =s1.pop(); //type casting char to int
						c = b*a;
						std::cout << "c : "<< c << '\n';
						s1.push(c);
						break;
				case '/':
						a= s1.pop(); //type casting char to int
						b =s1.pop(); //type casting char to int
						c = b/a;
						s1.push(c);
						break;
				default:
						s1.push(ch -'0');
//						s1.display();
						break;
	} // switch case closing
} // for loop closing
	std::cout << "Result = " << s1.pop();
	return(0);
}
