#include<iostream>
#include<typeinfo>
using namespace std;
template<class T>
class stack1{
	T *s;
     int size, top;
public:
	stack1()
	{
		s=NULL;
		size=0;
		top= -1;
//		cout<<"\n defult cont";
	}
	stack1(int a)
	{
		s= new T[a];
		size=a;
		top= -1;
//		cout<<"\n parameterised cont";
	}

	~stack1()
	{
		delete s;
		size=0;
		top= -1;
	}

	void get_size(int n)
	{
		s= new T[n];
		size= n;
	}
	void push(T);
	T pop();
	T peack();
	bool isFull();
	bool isEmpty();
	void display();
};

template<class T> void stack1<T>::push(T element){
	if(!isFull()){
		s[++top]= element;
		cout<<"\nElement pushed in stack : "<<s[top]<<endl;
	}else{
		cout<<" stack is full\n";
	}
}
template<class T> T stack1<T>::pop(){
	T x;
	if(typeid(T).name() == typeid(int).name()){
		cout<<"\n in if block tp is int  \n";
		x= -99;
	}else if(typeid(T).name() == typeid(char).name()){
		cout<<"\n in if block tp is float  \n";
		x= '\0';
	}else if(typeid(T).name() == typeid(float).name()){
		cout<<"\n in if block tp is char  \n";
		x= -22.4;
	}else{
		x= -99;
	}
//	cout<<"type is : "<<typeid(T).name();
//	cout<<"type is int : "<<typeid(int());


	if(!isEmpty()){
		x= s[top--];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}
template<class T> T stack1<T>::peack(){
	T x = -999;
	if(!isEmpty()){
		x= s[top];
	}else{
		cout<<"Satck is empty";
	}
	return (x);
}
template<class T> bool stack1<T>::isFull(){
	return(size-1 == top);
}
template<class T> bool stack1<T>::isEmpty(){
	return(top==-1);
}
template<class T> void stack1<T>::display(){
	int i;
	for(i=0;i<=top;i++){
		cout<<"\n "<<s[i];
	}
}
int main(){
	stack1<int> s1;
	stack1<int> s4(3);
	stack1<char> s5(2);
	stack1<char> s2;
	stack1<float> s3;
	int n,a;
	char ch;
	float f;
	s4.push(1);
	s4.push(2);
	s4.push(3);
	s4.push(4);
	s4.push(5);

	s4.display();
	a = s4.pop();
	cout<<"\n pop a = "<<a;
	a = s4.pop();
	cout<<"\n pop a = "<<a;

	cout<<"Enter the stack size for int type : ";
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

	cout<<"Enter the stack size for float type : ";
	cin>>n;
	s3.get_size(n);
	s3.push(20.5f);
	s3.push(10.5f);
	s3.push(30.5f);
	s3.push(40.3f);

	s3.display();
	f = s3.pop();
	cout<<"\n pop f = "<<f;
	f = s3.pop();
	cout<<"\n pop f = "<<f;

	cout<<"Enter the stack size for char type : ";
	cin>>n;
	s2.get_size(n);
	s2.push('a');
	s2.push('b');
	s2.push('c');
	s2.push('d');
	s2.push('e');

	s2.display();
	ch = s2.pop();
	cout<<"\n pop a = "<<ch;
	ch = s2.pop();
	cout<<"\n pop a = "<<ch;

//	s1.display();

//	a = s1.peack();
//	cout<<"\n peack a = "<<a;
//	s1.display();

	return(0);
}
