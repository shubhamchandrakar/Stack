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
		cout<<endl;
//		cout<<"in delete = "<<s;		
		delete s;
	//	cout<<"in delete = "<<s;
		size=10;
		top= 5;
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
		cout<<"\nElement pushed in stack : "<<s[top]<<endl;
	}else{
		cout<<" stack is full\n";
	}
}
char stack1::pop(){
	char x = -1;

	if(!isEmpty()){
		x= s[top--];
	}else{
		// cout<<"Satck is empty";
	}
	return (x);
}
char stack1::peak(){
	char x = -1;
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
	char str[30]= "a*[b+c+(d+e)]";
  char *ostr;//[24];
	cout<<"str : "<<str<<endl;
  int n,i,j= -1;
  char ch,pch;
  n = strlen(str);
  ostr=new char[n];
  bool x;
  // std::cout << "n : " <<n<< '\n';
  s1.get_size(n);
  for (i = 0; i < n; i++) {
    ch = str[i];
  	switch (ch) {
			case '(':
			case '[':
			case '{':
        	s1.push(ch);
        	break;
      case '+':
      case '*':
      case '/':
      case '-':
        	while (!s1.isEmpty()&&(precidence(s1.peak()) >= precidence(ch)  ) ) {
          	std::cout << "in while loop" << '\n';
         	 ostr[++j] = s1.pop();
        }
				s1.push(ch);
        break;
      case '}':
  		case ']':
  		case ')':
          while (1) {
            pch = s1.pop();
						if(!(pch== '('||pch == '{' || pch == '[' )){
						std::cout << "pch value : "<< pch << '\n';
						std::cout << "i value : "<< i << '\n';
              ostr[++j]= pch;
            }else{
            break;
            }
            // break;
          }// while loop closing
          break;
      default:
          ostr[++j]= ch;
        //break;

    }// switch closing
  }// for loop closing

  //std::cout << " 1 ostr : " << ostr<<"\n ";

  s1.display();
while (!s1.isEmpty()) {
  ostr[++j]= s1.pop();
//  cout << "/* message */" << '\n';
}
  cout << "ostr : " << ostr;
//  std::cout << " ostr len  : " << strlen(ostr)<<"\n ";

	return(0);
}


int precidence(char c){
  int x;
  switch (c) {
    case '*':
    case '/':
      x= 2;
      break;
    case '+':
    case '-':
      x= 1;
      break;
    case '(':
		case '[':
		case '{':
      x= 0;
      break;
    default:
      x= -1;
      break;
  }
  return x;
}
