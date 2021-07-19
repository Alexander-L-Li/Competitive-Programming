#include <iostream>
#include <stack>

using namespace std;

int main(){
  string text;
  cin >> text;
  stack <char> open;
  stack <char> close;
  stack <int> opos;
  stack <int> cpos;
  
  for(int a=0; a<text.length(); a++){
    if(text[a] == '[' || text[a] == '{' || text[a] == '('){
      open.push(text[a]);
      opos.push(a + 1);
    } 
    if(open.size() > 0 && ((open.top() == '[' && text[a] == ']') || (open.top() == '(' && text[a] == ')') || (open.top() == '{' && text[a] == '}'))){
      opos.pop();
      open.pop();
    } else if (text[a] == ']' || text[a] == '}' || text[a] == ')'){
      close.push(text[a]);
      cpos.push(a + 1);
    }
  }

  if(close.empty() == true && open.empty() == false){ 
  for(int a=0; a<open.size(); a++){
    if(a == open.size() - 1){
          cout << opos.top();
          break;
        }
        opos.pop();
      }
  } else if((close.empty() == false && open.empty() == true) || (close.empty() == false && open.empty() == false)){ 
      for(int b=0; b<close.size(); b++){
        if(b == close.size() - 1){
          cout << cpos.top();
          break;
        }
        cpos.pop();
      }
    } else if(close.empty() == true && open.empty() == true){ 
    cout << "Success";
    } 
    }
