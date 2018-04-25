#include<iostream>
#include<fstream>
using namespace std;
ifstream f("citire.in");

 class Nod {
protected:
    int info;
    Nod *next;
public:
    Nod();
    Nod(int info,Nod* next=0);
    Nod(Nod *p);
    virtual int getInfo();
    virtual Nod* getNext();
    Nod &operator =(const Nod &p);
    friend class ListaSimpluInlantuita;
    friend class ListaDubluInlantuita;
    friend class CoadaDePrioritati;
  };

Nod& Nod::operator=(const Nod &p){
    this->info=p.info;
    this->next=p.next;
    return *this;
}

Nod::Nod(){
 next=0;
}

Nod::Nod(int info, Nod* next){
 this->info=info;
 this->next=next;
}

int Nod::getInfo(){
     return info;
}

 Nod* Nod::getNext(){
     return next;
}

Nod::Nod(Nod *p){
this->info=p->info;
this->next=p->next;
}

class Nod_dublu:public Nod{
protected:
    Nod *ante;
public:
    Nod_dublu();
    Nod_dublu(int info, Nod *next=0, Nod *ante=0);
    Nod_dublu(Nod_dublu *p);
   // int getInfo();
   // Nod *getNext();
    Nod *getAnte();
    Nod_dublu &operator=(const Nod_dublu &p);
    friend class ListaDubluInlantuita;
};

Nod_dublu::Nod_dublu(){
 next=0;
 ante=0;
}

Nod_dublu::Nod_dublu(int info, Nod *next, Nod *ante){
this->info=info;
this->next=next;
this->ante=ante;
}

/*int Nod_dublu::getInfo(){
return info;
}*/

/*Nod* Nod_dublu::getNext(){
return next;
}*/

Nod_dublu::Nod_dublu(Nod_dublu *p){
this->info=p->info;
this->next=p->next;
this->ante=p->ante;
}

Nod* Nod_dublu::getAnte(){
return ante;
}

Nod_dublu& Nod_dublu::operator=(const Nod_dublu &p){
    this->info=p.info;
    this->next=p.next;
    return *this;
}

class Nod_prioritate:public Nod_dublu{
int prio;
public:
    Nod_prioritate();
    Nod_prioritate(int info,int prio);
    Nod_prioritate(int info, Nod *next, Nod *ante, int prio);
    Nod_prioritate(Nod_prioritate *p);
    int getPrio();
    Nod_prioritate &operator=(const Nod_prioritate &p);
};

Nod_prioritate::Nod_prioritate(){
    next=0;
    ante=0;
}

Nod_prioritate::Nod_prioritate(int info,int prio){
    this->info=info;
    this->prio=prio;
}

Nod_prioritate::Nod_prioritate(int info,Nod *next,Nod *ante,int prio){
    this->info=info;
    this->next=next;
    this->ante=ante;
    this->prio=prio;
}

int Nod_prioritate::getPrio(){
return prio;
}

Nod_prioritate::Nod_prioritate(Nod_prioritate *p){
this->info=p->info;
this->next=p->next;
this->ante=p->ante;
this->prio=p->prio;
}

Nod_prioritate& Nod_prioritate::operator=(const Nod_prioritate &p){
    this->info=p.info;
    this->next=p.next;
    return *this;
}

class ListaSimpluInlantuita {
protected:
    Nod *prim;
    Nod *ultim;
public:
    ListaSimpluInlantuita();
    virtual ~ListaSimpluInlantuita();
    ListaSimpluInlantuita(const ListaSimpluInlantuita &);
    int isEmpty();
    virtual void addElement(Nod n);
    Nod* getFirst();
    Nod* getLast();
    friend istream& operator>>(istream&,ListaSimpluInlantuita&);
    friend ostream& operator<<(ostream& out, ListaSimpluInlantuita&);
    ListaSimpluInlantuita &operator =(const ListaSimpluInlantuita&);
    virtual void stergere(int);
    virtual void adaugare(int x, int poz);
    void existenta(int);
    const int & operator[] (int);
    const ListaSimpluInlantuita& operator +(const ListaSimpluInlantuita&);
    };

ListaSimpluInlantuita& ListaSimpluInlantuita::operator=(const ListaSimpluInlantuita &d){
        Nod *p;
        if(!this->isEmpty()){
        p=prim;
    Nod *q;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
        }
       prim=ultim = 0;
    p=d.prim;
    while(p){
        this->addElement(p->info);
        p=p->next;
    }
    return *this;
    }

 ListaSimpluInlantuita::ListaSimpluInlantuita(){
    prim=ultim=0;
}

ListaSimpluInlantuita::~ListaSimpluInlantuita(){
    Nod *p=prim;
    Nod *q;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
       prim=ultim = 0;
}

ListaSimpluInlantuita::ListaSimpluInlantuita(const ListaSimpluInlantuita &c){
    prim=ultim=0;
    Nod *p=c.prim;
    while(p)
    {
        this->addElement(p->info);
        p=p->next;
    }
}

int ListaSimpluInlantuita::isEmpty(){
     return prim==0;
}

void ListaSimpluInlantuita::addElement(Nod n){
   Nod *p;
   p=new Nod(n.info,0);
   if(isEmpty()){
   prim=ultim=p;
     }
     else {
   ultim->next=p;
      ultim = p;
     }
}

Nod* ListaSimpluInlantuita::getFirst(){
     return prim;
}

Nod* ListaSimpluInlantuita::getLast(){
   return ultim;
}

ostream& operator<<(ostream& out, ListaSimpluInlantuita& lista){
     Nod * p=lista.getFirst();
 while(p){
      cout<<p->getInfo()<<",";
      p=p->getNext();
     }
     cout<<"\b ";
 return out;
}

istream& operator>>(istream& in, ListaSimpluInlantuita& l){
int x;
in>>x;
l.addElement(x);
while(in.get()!='\n')
{
    in>>x;
    l.addElement(x);
}
return in;
}

void ListaSimpluInlantuita::stergere(int x){
    Nod *p=prim,*q;
    if(p->info==x){
        prim=prim->next;
        delete p;
    }
    else{
    p=prim;
    while(p->next->next)
        p=p->next;
    if(p->next->info==x)
    {
        q=ultim;
        ultim=p;
        delete q;
    }
    else{
    p=prim;
    while(p->next){
        if(p->next->info==x)
            {q=p->next;
             delete q;
             p->next=p->next->next;}
        p=p->next;
    }
    }
    }
}

void ListaSimpluInlantuita::adaugare(int x,int poz){
    Nod *p=prim,*c;
    c=new Nod(x);
    int i=1;
    while(i<poz-1&&p)
        {p=p->next;
        i++;}
    if(p!=prim){
        c->next=p->next;
        p->next=c;
    }
    else{c->next=prim;
         prim=c;}
}

void ListaSimpluInlantuita::existenta(int x){
    int sem=0;
    Nod *p=prim;
    while(p){
        if(p->info==x)sem=1;
        p=p->next;
    }
    if(!sem)cout<<"Elementul "<<x<<" nu se afla in lista";
      else cout<<"Elementul "<<x<<" se afla in lista, la pozitiile:";
    p=prim;
    int i=1;
    while(p){
        if(p->info==x)cout<<i<<" ";
        p=p->next;
        i++;
    }
}

const int& ListaSimpluInlantuita::operator[](int k){
    Nod *p=prim;
    for(int i=1;i<k;i++)
        p=p->next;
    return p->info;
}

const ListaSimpluInlantuita& ListaSimpluInlantuita::operator+(const ListaSimpluInlantuita &l){
    Nod *q=l.prim;
    while(q){
        (*this).addElement(q->info);
        q=q->next;
    }
    return (*this);
}


class ListaDubluInlantuita:public ListaSimpluInlantuita{                      //Mai adaug o lista simpla care sa retina elementele invers(pt a simula o lista dubla)
protected:
    Nod* prim1;
    Nod* ultim1;
public:
    ListaDubluInlantuita();
    ListaDubluInlantuita(const ListaDubluInlantuita&);
    virtual ~ListaDubluInlantuita();
    virtual void addElement(Nod);
    Nod* getFirst1();
    friend istream& operator>>(istream&,ListaDubluInlantuita&);
    friend ostream& operator<<(ostream& out, ListaDubluInlantuita&);
    ListaDubluInlantuita &operator =(const ListaDubluInlantuita&);
    virtual void stergere(int);
    void adaugare(int x, int poz);
    const ListaDubluInlantuita& operator +(const ListaDubluInlantuita&);
};

ListaDubluInlantuita::ListaDubluInlantuita(){
    prim=ultim=0;
    prim1=ultim1=0;
}

ListaDubluInlantuita::ListaDubluInlantuita(const ListaDubluInlantuita& c){
    prim=ultim=0;
    prim1=ultim1=0;
    Nod *p=c.prim;
    while(p)
    {
        this->addElement(p->info);
        p=p->next;
    }
}

ListaDubluInlantuita::~ListaDubluInlantuita(){
     Nod *p=prim;
    Nod *q;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
       prim=ultim=0;

     p=prim1;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
       prim1=ultim1=0;
}

void ListaDubluInlantuita::addElement(Nod n){
   Nod *p,*p1;
   p=new Nod(n.info,0);
   p1=new Nod(n.info,0);
   if(isEmpty()){
   prim=ultim=p;
   prim1=ultim1=p1;
     }
     else {
   ultim->next=p;
      ultim = p;
      p1->next=prim1;
      prim1=p1;
     }
}

istream& operator>>(istream& in, ListaDubluInlantuita& l){
int x;
in>>x;
l.addElement(x);
while(in.get()!='\n')
{
    in>>x;
    l.addElement(x);
}
return in;
}

Nod* ListaDubluInlantuita::getFirst1(){
return prim1;
}

ostream& operator<<(ostream& out, ListaDubluInlantuita& lista){
     Nod * p=lista.getFirst();
 while(p){
      cout<<p->getInfo()<<",";
      p=p->getNext();
     }
     cout<<"\b ";
     p=lista.getFirst1();
     cout<<"\n";
 while(p){
      cout<<p->getInfo()<<",";
      p=p->getNext();
     }
     cout<<"\b ";
 return out;
}

ListaDubluInlantuita& ListaDubluInlantuita::operator=(const ListaDubluInlantuita &d){
        Nod *p;
        if(!this->isEmpty()){
        p=prim;
    Nod *q;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }

    p=prim1;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
    }

       prim=ultim = 0;
       prim1=ultim1=0;
    p=d.prim;
    while(p){
        this->addElement(p->info);
        p=p->next;
    }
    return *this;
}

void ListaDubluInlantuita::stergere(int x){
    Nod *p=prim,*q;
    if(p->info==x){
        prim=prim->next;
        delete p;
    }
    else {
    p=prim;
    while(p->next->next)
        p=p->next;
    if(p->next->info==x)
    {
        q=ultim;
        ultim=p;
        delete q;
    }
    else{
    p=prim;
    while(p->next){
        if(p->next->info==x)
            if(p->next->next){q=p->next;
                             delete q;
                             p->next=p->next->next;}
              else {q=p->next;
                    delete q;
                    p->next=p->next->next;ultim=p;}
        p=p->next;
    }}}
    p=prim1;
    if(p->info==x){
        prim1=prim1->next;
        delete p;
    }
    else{
     p=prim1;
    while(p->next->next)
        p=p->next;
    if(p->next->info==x)
    {
        q=ultim1;
        ultim1=p;
        delete q;
    }
    else{
    p=prim1;
    while(p->next){
        if(p->next->info==x)
             if(p->next->next){q=p->next;
                    delete q;
                    p->next=p->next->next;}
              else {q=p->next;
                    delete q;
                    p->next=p->next->next;ultim1=p;}
        p=p->next;
    }}}
}

void ListaDubluInlantuita::adaugare(int x,int poz){
    int nr=0;
    Nod *p=prim,*c,*d;
    c=new Nod(x);
    d=new Nod(x);
    while(p){nr++;p=p->next;}
    p=prim;
    int i=1;
    while(i<poz-1&&p)
        {p=p->next;
        i++;}
    if(p)
        if(p!=prim){
        c->next=p->next;
        p->next=c;
    } else{c->next=prim;
         prim=c;}
    p=prim1;
    i=1;
    while(i<nr-poz+1&&p){
        p=p->next;
        i++;
    }
    d->next=p->next;
    p->next=d;
}

const ListaDubluInlantuita& ListaDubluInlantuita::operator+(const ListaDubluInlantuita &l){
    Nod *q=l.prim;
    while(q){
        (*this).addElement(q->info);
        q=q->next;
    }
    return (*this);
}

class CoadaDePrioritati:public ListaDubluInlantuita{
public:
    CoadaDePrioritati();
    CoadaDePrioritati(const CoadaDePrioritati&);
    ~CoadaDePrioritati();
    void addElement(Nod,int);
    friend istream& operator>>(istream&,CoadaDePrioritati&);                  // citesc elentele, fiecare urmat de prioritatea lui(toate pe un rand)
    CoadaDePrioritati &operator =(const CoadaDePrioritati&);
    const CoadaDePrioritati &operator +(const CoadaDePrioritati&);
    void stergere();
};

CoadaDePrioritati::CoadaDePrioritati(){
    prim=ultim=0;
    prim1=ultim1=0;
}

void CoadaDePrioritati::addElement(Nod n,int prio){
   Nod *p,*p1;
   p=new Nod(n.info,0);
   p1=new Nod(prio,0);
   if(isEmpty()){
   prim=ultim=p;
   prim1=ultim1=p1;
     }
     else {
   ultim->next=p;
      ultim = p;
    ultim1->next=p1;
      ultim1 = p1;
     }

     int i=1,j,nr=0,aux;
     Nod *q,*q1,*r,*r1;
     q=prim1;
     while(q)
     {
         nr++;
         q=q->next;
     }
     int sem;
     do
     {
         i=1;
         sem=0;
         while(i<=nr/2){
          q=prim1;q1=prim1;r=prim;r1=prim;
             for(j=1;j<i;j++){
                q=q->next;
                r=r->next;
             }
             for(j=1;j<2*i;j++){
                q1=q1->next;
                r1=r1->next;
             }
         if(q->info<q1->info)
         {
             aux=q->info;
             q->info=q1->info;
             q1->info=aux;
             aux=r->info;
             r->info=r1->info;
             r1->info=aux;
             sem=1;
         }
         if(q1->next){
           q1=q1->next;
           r1=r1->next;
         }
          if(q->info<q1->info)
         {
             aux=q->info;
             q->info=q1->info;
             q1->info=aux;
             aux=r->info;
             r->info=r1->info;
             r1->info=aux;
             sem=1;
         }
         i++;
         }
     }while(sem);
}

CoadaDePrioritati::CoadaDePrioritati(const CoadaDePrioritati& c){
    prim=ultim=0;
    prim1=ultim1=0;
    Nod *p=c.prim;
    Nod *p1=c.prim1;
    while(p)
    {
        this->addElement(p->info,p1->info);
        p=p->next;
        p1=p1->next;
    }
}

CoadaDePrioritati::~CoadaDePrioritati(){
     Nod *p=prim;
    Nod *q;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
       prim=ultim=0;

     p=prim1;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
       prim1=ultim1=0;
}

istream& operator>>(istream& in, CoadaDePrioritati& l){
int x,y;
in>>x>>y;
l.addElement(x,y);
while(in.get()!='\n')
{
    in>>x>>y;
    l.addElement(x,y);
}
return in;
}

void CoadaDePrioritati::stergere(){
    Nod*p=prim1;
    prim1=prim1->next;
    delete p;
    p=prim1;
    while(p->next->next)
          p=p->next;
    ultim1->next=prim1;
    prim1=ultim1;
    ultim1=p;
    delete p->next;
    p->next=NULL;

    p=prim;
    prim=prim->next;
    delete p;
    p=prim;
    while(p->next->next)
          p=p->next;
    ultim->next=prim;
    prim=ultim;
    ultim=p;
    delete p->next;
    p->next=NULL;

    int i=1,j,nr=0,aux;
     Nod *q,*q1,*r,*r1;
     q=prim1;
     while(q)
     {
         nr++;
         q=q->next;
     }
     int sem;
     do
     {
         i=1;
         sem=0;
         while(i<=nr/2){
          q=prim1;q1=prim1;r=prim;r1=prim;
             for(j=1;j<i;j++){
                q=q->next;
                r=r->next;
             }
             for(j=1;j<2*i;j++){
                q1=q1->next;
                r1=r1->next;
             }
         if(q->info<q1->info)
         {
             aux=q->info;
             q->info=q1->info;
             q1->info=aux;
             aux=r->info;
             r->info=r1->info;
             r1->info=aux;
             sem=1;
         }
         if(q1->next){
           q1=q1->next;
           r1=r1->next;
         }
          if(q->info<q1->info)
         {
             aux=q->info;
             q->info=q1->info;
             q1->info=aux;
             aux=r->info;
             r->info=r1->info;
             r1->info=aux;
             sem=1;
         }
         i++;
         }
     }while(sem);
}

CoadaDePrioritati& CoadaDePrioritati::operator=(const CoadaDePrioritati &d){
        Nod *p,*q;
        if(!this->isEmpty()){
        p=prim;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
    p=prim1;
    while(p!=0){
        q = p;
        p = p->next;
        delete q;
       }
    }
       prim=ultim = 0;
       prim1=ultim1=0;
    p=d.prim;
    q=d.prim1;
    while(p){
        this->addElement(p->info,q->info);
        p=p->next;
        q=q->next;
    }
    return *this;
}

const CoadaDePrioritati& CoadaDePrioritati::operator+(const CoadaDePrioritati &l){
    Nod *q=l.prim,*r=l.prim1;
    while(q){
        (*this).addElement(q->info,r->info);
        q=q->next;
        r=r->next;
    }
    return (*this);
}


int main()
{
cout<<"Exemplu pt nod:\n";
    Nod_prioritate *p,*g;
    p=new Nod_prioritate(4,1);
    cout<<p->getInfo()<<" "<<p->getPrio()<<"\n";
    g=new Nod_prioritate(p);
     cout<<g->getInfo()<<" "<<g->getPrio()<<"\n";
     Nod *r1,*r2;
     r1=new Nod(55);
     r2=new Nod;
     r2=r1;
     cout<<r2->getInfo()<<"\n\n";
     delete(r1);delete(r2);delete(p);delete(g);

cout<<"Exemplu pt lista simplu inlantuita:\n";
     ListaSimpluInlantuita *l;
    int n,i;
    f>>n;
    l=new ListaSimpluInlantuita[n+3];
     for(i=1;i<=n;i++)
        f>>l[i];
     for(i=1;i<=n;i++)
        cout<<l[i]<<'\n';
    cout<<'\n';

    l[1].stergere(3);
    cout<<l[1]<<"\n\n";

    l[1].adaugare(33,1);
    cout<<l[1]<<"\n\n";

    l[3].existenta(16);
    cout<<"\n\n";

    delete[]l;
    ListaSimpluInlantuita a1,a2,a;
    f>>a1>>a2;
    a=a1;
    a+a2;
    cout<<a1<<"\n"<<a<<"\n\n";

cout<<"Exemplu pt lista dublu inlantuita:\n";

    ListaDubluInlantuita ls;
    f>>ls;
    cout<<ls<<"\n\n";
    ListaDubluInlantuita x(ls),y;
    y=x;
    x.stergere(5);
    y.adaugare(3,3);
    cout<<x<<"\n\n"<<y<<"\n\n";
    x+y;
    cout<<x<<"\n\n";

cout<<"Exeplu pt coada de prioritati:\n";
    CoadaDePrioritati c,e;
    f>>c;
    cout<<c<<"\n\n";
    c.stergere();
    c.stergere();
    CoadaDePrioritati d(c);
    cout<<d<<"\n\n";
    f>>e;
    d+e;
    cout<<d<<"\n\n";
     return 0;
}
