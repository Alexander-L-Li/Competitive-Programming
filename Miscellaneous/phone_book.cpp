#include <iostream>
#include <vector>

using namespace std;

struct query {
  string type, name;
  int number;
};

struct query2 {
  int num;
  string name;
};

int main() {
  int n; cin >> n;
  vector <query> book(n);
  vector <query2> contacts;
  vector <string> ans;
  for(int a=0; a<n; a++){
    cin >> book[a].type;
    if(book[a].type == "add"){
      cin >> book[a].number >> book[a].name;
    } else {
      cin >> book[a].number;
    }
  }
  for(int a=0; a<n; a++){
    if(book[a].type == "add"){
      bool replaced = false;
      for(int b=0; b<contacts.size(); b++){
        if(book[a].number == contacts[b].num){
          contacts[b].num = book[a].number;
          contacts[b].name = book[a].name;
          replaced = true;
          break;
        } 
      }
      if(replaced == false){
        query2 temp = {book[a].number, book[a].name};
        contacts.push_back(temp);
      }
    } else if (book[a].type == "del"){
      for(int b=0; b<contacts.size(); b++){
        if(book[a].number == contacts[b].num){
          contacts.erase(contacts.begin() + b); 
        } 
      }
    } else if (book[a].type == "find"){
      bool found = false;
      for(int b=0; b<contacts.size(); b++){
        if(book[a].number == contacts[b].num){
          ans.push_back(contacts[b].name);
          found = true;
          break;
        } 
      }
      if(found == false){
        ans.push_back("not found");
      }
    }
  }
  for(int a=0; a<ans.size(); a++){
    cout << ans[a] << "\n";
  }
}
