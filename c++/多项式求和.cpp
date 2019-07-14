#include <iostream>
#include <algorithm>
#include <stack>
#include <stdlib.h>
#include <string>
#include <list>

using namespace std;
const int optContainer[8][8]={{-1,0,-1,-1,2,-1,2,-1},{2,1,1,1,2,1,2,1},{-1,1,1,1,2,1,2,1},{-1,1,-1,1,2,1,2,-1},{2,2,2,2,2,2,2,2},{-1,1,-1,1,2,1,2,-1},{2,2,2,2,2,2,2,2},{-1,1,1,1,2,1,1,1}};
int isopn(char i);
int optCompare(char opt1,char opt2);
int opt_cal(char i,int a,int b);
int main() {
    stack<char> optStack;
    stack<int> opnStack;

    string expression;
    cin>>expression;
    for(unsigned int i=0;i<=expression.length();++i){
        if(isopn(expression[i])) {
            opnStack.push(expression[i]-'0');
        }
        else {
            if(optStack.empty()){
                optStack.push(expression[i]);
            }
            else
                switch (optCompare(optStack.top(),expression[i])) {
                    case 1: {
                        char opt = optStack.top();
                        optStack.pop();
                        optStack.push(expression[i]);
                        int opn_a = opnStack.top();
                        opnStack.pop();
                        int opn_b = opnStack.top();
                        opnStack.pop();
                        opnStack.push(opt_cal(opt, opn_a, opn_b));
                        break;
                    }
                    case 0: {
                        optStack.pop();
                        break;
                    }
                    case -1: {
                        optStack.push(expression[i]);
                        break;
                    }
					case 3: {
						while (optStack.size() != 0) {
							char opt = optStack.top();
							optStack.pop();
							int opn_a = opnStack.top();
							opnStack.pop();
							int opn_b = opnStack.top();
							opnStack.pop();
							opnStack.push(opt_cal(opt, opn_a, opn_b));
							
						}
					}

                }


        }
    }
	cout << opnStack.top();
    system("pause");
    return 0;
}
int isopn(char i){
    if (i<=57 &&i>=48){
        return 1;
    }
    else return 0;
}

int opt_cal(char i,int a,int b){
    switch (i){
        case '*':return a * b;
        case '/':return b/a;
        case '+':return a+b;
        case '-':return b-a;
        default:return 0;
    }
}


int optCompare(char top_opt,char new_opt){
	if (new_opt == '\0') return 3;

    return optContainer[top_opt-'('][new_opt-'('];

}
