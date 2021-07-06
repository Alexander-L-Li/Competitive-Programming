#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;

int main() {
  ifstream fin("tttt.in");
  ofstream fout("tttt.out");
  char pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;
  vector<char>onet;
  vector<string>twot;
  string s;
  int c1 = 0, c2 = 0;
  int ans = 0, ans2 = 0;
  fin >> pos1; fin >> pos2; fin >> pos3; fin >> pos4;
  fin >> pos5; fin >> pos6; fin >> pos7; fin >> pos8; fin >> pos9;
  if(pos1 == pos2 && pos2 == pos3){
    ans += 1;
    onet.push_back(pos1);
  } else if(pos1 == pos2 || pos2 == pos3 || pos1 == pos3){
    ans2 += 1;
    if(pos1 == pos2){
      s += pos1; s += pos3;
      twot.push_back(s); s = "";
      s += pos3; s += pos1;
      twot.push_back(s); s = "";
    } else if (pos2 == pos3){
      s += pos2; s += pos1;
      twot.push_back(s); s = "";
      s += pos1; s += pos2;
      twot.push_back(s); s = "";
    } else if (pos1 == pos3){
      s += pos2; s += pos3;
      twot.push_back(s); s = "";
      s += pos3; s += pos2;
      twot.push_back(s); s = "";
    }
  }
  if(pos4 == pos5 && pos5 == pos6){
    ans += 1;
    onet.push_back(pos4);
  } else if (pos4 == pos5 || pos5 == pos6 || pos4 == pos6){
    ans2 += 1;
    if(pos4 == pos5){
      s += pos4; s += pos6;
      twot.push_back(s); s = "";
      s += pos6; s += pos4;
      twot.push_back(s); s = "";
    } else if (pos5 == pos6){
      s += pos5; s += pos4;
      twot.push_back(s); s = "";
      s += pos4; s += pos5;
      twot.push_back(s); s = "";
    } else if (pos4 == pos6){
      s += pos5; s += pos6;
      twot.push_back(s); s = "";
      s += pos6; s += pos5;
      twot.push_back(s); s = "";
    }
  }
  if(pos7 == pos8 && pos8 == pos9){
    ans += 1;
    onet.push_back(pos7);
  } else if (pos7 == pos8 || pos8 == pos9 || pos7 == pos9){
    ans2 += 1;
    if(pos7 == pos8){
      s += pos7; s += pos9;
      twot.push_back(s); s = "";
      s += pos9; s += pos7;
      twot.push_back(s); s = "";
    } else if (pos8 == pos9){
      s += pos7; s += pos8;
      twot.push_back(s); s = "";
      s += pos8; s += pos7;
      twot.push_back(s); s = "";
    } else if (pos7 == pos9){
      s += pos8; s += pos9;
      twot.push_back(s); s = "";
      s += pos9; s += pos8;
      twot.push_back(s); s = "";
    }
  }
  if(pos1 == pos4 && pos4 == pos7){
    ans += 1;
    onet.push_back(pos1);
  } else if (pos1 == pos4 || pos4 == pos7 || pos1 == pos7){
    ans2 += 1;
    if(pos1 == pos4){
      s += pos1; s += pos7;
      twot.push_back(s); s = "";
      s += pos7; s += pos1;
      twot.push_back(s); s = "";
    } else if (pos4 == pos7){
      s += pos1; s += pos4;
      twot.push_back(s); s = "";
      s += pos4; s += pos1;
      twot.push_back(s); s = "";
    } else if (pos1 == pos7){
      s += pos4; s += pos7;
      twot.push_back(s); s = "";
      s += pos7; s += pos4;
      twot.push_back(s); s = "";
    }
  } 
  if(pos2 == pos5 && pos5 == pos8){
    ans += 1;
    onet.push_back(pos2);
  } else if (pos2 == pos5 || pos5 == pos8 || pos2 == pos8){
    ans2 += 1;
    if(pos2 == pos5){
      s += pos2; s += pos8;
      twot.push_back(s); s = "";
      s += pos8; s += pos2;
      twot.push_back(s); s = "";
    } else if (pos5 == pos8){
      s += pos2; s += pos5;
      twot.push_back(s); s = "";
      s += pos5; s += pos2;
      twot.push_back(s); s = "";
    } else if (pos2 == pos8){
      s += pos5; s += pos8;
      twot.push_back(s); s = "";
      s += pos8; s += pos5;
      twot.push_back(s); s = "";
    }
  }
  if(pos3 == pos6 && pos6 == pos9){
    ans += 1;
    onet.push_back(pos3);
  } else if(pos3 == pos6 || pos6 == pos9 || pos3 == pos9){
    ans2 += 1;
    if(pos3 == pos6){
      s += pos3; s += pos9;
      twot.push_back(s); s = "";
      s += pos9; s += pos3;
      twot.push_back(s); s = "";
    } else if (pos6 == pos9){
      s += pos6; s += pos3;
      twot.push_back(s); s = "";
      s += pos3; s += pos6;
      twot.push_back(s); s = "";
    } else if (pos3 == pos9){
      s += pos6; s += pos9;
      twot.push_back(s); s = "";
      s += pos9; s += pos6;
      twot.push_back(s); s = "";
    }
  }
  if(pos1 == pos5 && pos5 == pos9){
    ans += 1;
    onet.push_back(pos1);
  } else if (pos1 == pos5 || pos5 == pos9 || pos1 == pos9){
    ans2 += 1;
    if(pos1 == pos5){
      s += pos1; s += pos9;
      twot.push_back(s); s = "";
      s += pos9; s += pos1;
      twot.push_back(s); s = "";
    } else if (pos5 == pos9){
      s += pos1; s += pos5;
      twot.push_back(s); s = "";
      s += pos5; s += pos1;
      twot.push_back(s); s = "";
    } else if (pos1 == pos9){   
      s += pos5; s += pos9;
      twot.push_back(s); s = "";
      s += pos9; s += pos5;
      twot.push_back(s); s = "";
    }
  }
  if(pos3 == pos5 && pos5 == pos7){
    ans += 1;
    onet.push_back(pos3);
  } else if (pos3 == pos5 || pos5 == pos7 || pos3 == pos7){
    ans2 += 1;
    if(pos3 == pos5){
      s += pos3; s += pos7;
      twot.push_back(s); s = "";
      s += pos7; s += pos3;
      twot.push_back(s); s = "";
    } else if (pos5 == pos7){
      s += pos5; s += pos3;
      twot.push_back(s); s = "";
      s += pos3; s += pos5;
      twot.push_back(s); s = "";
    } else if (pos3 == pos7){
      s += pos5; s += pos7;
      twot.push_back(s); s = "";
      s += pos7; s += pos5;
      twot.push_back(s); s = "";
    }
  }
  for(int i=0; i<onet.size(); i++){
    for(int j=0; j<onet.size(); j++){
      if(onet[i] == onet[j] && i != j){
        c1 += 1;
      }
    }
  }
  if(ans == onet.size() && ans != 0 && c1 > onet.size()){
    c1 = c1/onet.size();
  } else {
    c1 = c1/2;
  }
  for(int i=0; i<twot.size(); i++){
    cout << twot[i] << "\n";
    for(int j=0; j<twot.size(); j++){
      if(twot[i] == twot[j] && i != j){
        c2 += 1;
      }
    }
  }
    cout << ans2 << " " << c2 << " " << twot.size();
  if(c2 != 0 && ans2 % 2 == 0){
    c2 = c2/twot.size();
  } else if (c2 != 0 && ans2 % 2 != 0){
    c2 = c2/(twot.size()/2);
  } 
  fout << ans-c1 << "\n" << ans2 - c2;
}
