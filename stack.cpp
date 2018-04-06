#include<iostream>
using namespace std;
class stack1{
	int *s;
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
		// cout<<"in delete = "<<s;
		size=0;
		top= -1;
	}

	void get_size(int);
	void push(int);
	int pop();
	int peack();
	bool isFull();
	bool isEmpty();
	void display();
};
void stack1::get_size(int n){
	s= new int[n];
	size= n;
}
void stack1::push(int element){
	if(!isFull()){
		s[++top]= element;
		cout<<"\nElement pushed in stack : "<<s[top]<<endl;
	}else{
		cout<<" stack is full\n";
	}
}
int stack1::pop(){
	int x = -999;

	if(!isEmpty()){
		x= s[top--];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}
int stack1::peack(){
	int x = -999;
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
	int n,a;
	cout<<"Enter the stack size : ";
	cin>>n;
	s1.get_size(n);
	s1.push(2);
	s1.push(1);
	s1.push(5);
	s1.push(7);
	s1.push(9);

	s1.display();
	a = s1.pop();
	cout<<"\n pop a = "<<a;
	a = s1.pop();
	cout<<"\n pop a = "<<a;

//	s1.display();

//	a = s1.peack();
//	cout<<"\n peack a = "<<a;
//	s1.display();

	return(0);
}
