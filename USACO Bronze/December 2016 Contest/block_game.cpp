#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin("blocks.in");
  ofstream fout("blocks.out");
  int n; fin >> n;
  int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n1=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
  int ta=0, tb=0, tc=0, td=0, te=0, tf=0, tg=0, th=0, ti=0, tj=0, tk=0, tl=0, tm=0, tn1=0, to=0, tp=0, tq=0, tr=0, ts=0, tt=0, tu=0, tv=0, tw=0, tx=0, ty=0, tz = 0;
  int ansa=0,ansb=0,ansc=0,ansd=0,anse=0,ansf=0,ansg=0,ansh=0,ansi=0,ansj=0,ansk=0,ansl=0,ansm=0,ansn1=0,anso=0,ansp=0,ansq=0,ansr=0,anss=0,anst=0,ansu=0,ansv=0,answ=0,ansx=0,ansy=0,ansz=0;
  string word[n*2];
  for(int i=0; i<n*2; i++){
    fin >> word[i];
  }
  for(int ind1=0; ind1<n; ind1++){
    for(int ind2=0; ind2<2; ind2++){
      string str = word[ind1*2 + ind2];
      for(int ltr=0; ltr < str.length(); ltr++){
        if(str.at(ltr) == 'a'){ ta += 1; } 
        else if(str.at(ltr) == 'b'){ tb += 1; }
        else if(str.at(ltr) == 'c'){ tc += 1; }
        else if(str.at(ltr) == 'd'){ td += 1; }
        else if(str.at(ltr) == 'e'){ te += 1; }
        else if(str.at(ltr) == 'f'){ tf += 1; }
        else if(str.at(ltr) == 'g'){ tg += 1; }
        else if(str.at(ltr) == 'h'){ th += 1; }
        else if(str.at(ltr) == 'i'){ ti += 1; }
        else if(str.at(ltr) == 'j'){ tj += 1; }
        else if(str.at(ltr) == 'k'){ tk += 1; }
        else if(str.at(ltr) == 'l'){ tl += 1; }
        else if(str.at(ltr) == 'm'){ tm += 1; }
        else if(str.at(ltr) == 'n'){ tn1 += 1; }
        else if(str.at(ltr) == 'o'){ to += 1; }
        else if(str.at(ltr) == 'p'){ tp += 1; }
        else if(str.at(ltr) == 'q'){ tq += 1; }
        else if(str.at(ltr) == 'r'){ tr += 1; }
        else if(str.at(ltr) == 's'){ ts += 1; }
        else if(str.at(ltr) == 't'){ tt += 1; }
        else if(str.at(ltr) == 'u'){ tu += 1; }
        else if(str.at(ltr) == 'v'){ tv += 1; }
        else if(str.at(ltr) == 'w'){ tw += 1; }
        else if(str.at(ltr) == 'x'){ tx += 1; }
        else if(str.at(ltr) == 'y'){ ty += 1; }
        else if(str.at(ltr) == 'z'){ tz += 1; }
      }
      a = max(a, ta); b = max(b, tb); c = max(c, tc); d = max(d, td); e = max(e, te); f = max(f, tf); g = max(g, tg); h = max(h, th); i = max(i, ti); j = max(j,tj); k=max(k,tk); l=max(l,tl); m=max(m, tm); n1=max(n1,tn1); o=max(o,to); p=max(p,tp); q=max(q,tq); r=max(r,tr); s = max(s,ts); t=max(t,tt); u=max(u,tu); v=max(v,tv); w=max(w,tw); x=max(x,tx); y=max(y,ty); z=max(z,tz);
      ta=0, tb=0, tc=0, td=0, te=0, tf=0, tg=0, th=0, ti=0, tj=0, tk=0, tl=0, tm=0, tn1=0, to=0, tp=0, tq=0, tr=0, ts=0, tt=0, tu=0, tv=0, tw=0, tx=0, ty=0, tz = 0;
    }
    ansa += a; ansb += b; ansc += c; ansd += d; anse += e; ansf += f; ansg += g; ansh += h; ansi += i; ansj += j; ansk += k; ansl += l; ansm += m; ansn1 += n1; anso += o, ansp += p, ansq += q, ansr += r, anss += s; anst += t; ansu += u; ansv += v; answ += w; ansx += x; ansy += y; ansz += z;
    a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n1=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
    ta=0, tb=0, tc=0, td=0, te=0, tf=0, tg=0, th=0, ti=0, tj=0, tk=0, tl=0, tm=0, tn1=0, to=0, tp=0, tq=0, tr=0, ts=0, tt=0, tu=0, tv=0, tw=0, tx=0, ty=0, tz = 0;
  }
  fout << ansa << "\n" << ansb << "\n" << ansc << "\n" << ansd << "\n" << anse << "\n" << ansf << "\n" << ansg << "\n" << ansh << "\n" << ansi << "\n" << ansj << "\n"<< ansk << "\n"<< ansl << "\n"<< ansm << "\n"<< ansn1 << "\n"<< anso << "\n"<< ansp << "\n"<< ansq << "\n"<< ansr << "\n"<< anss << "\n"<< anst << "\n"<< ansu << "\n"<< ansv << "\n"<< answ << "\n"<< ansx << "\n"<< ansy << "\n" << ansz;

}
