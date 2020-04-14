#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <cstdlib>

using namespace std;

class Point
{
public:
int x_;
int y_;
Point(int xx,int yy)
{
x_=xx;
y_=yy;
}
Point()
{
x_=0;
y_=0;
}
Point(double a, double b)
{
x_=a;
y_=b;
}
Point(Point &a){
x_ = a.x_;
y_ = a.y_;
}
int x()
{return x_;}
int y()
{return y_;}
void PPrint()
{cout<< '('<< this->x_<<',' << this->y_ <<')'<<endl; }

void reset(int a, int b)
{this->x_=a; this->y_=b;}
int operator*(Point const &p){return  (this->x_*p.y_ -this->y_*p.x_);}
Point operator+(Point  &p){Point aa; aa.x_=this->x_+p.x_; aa.y_=this->y_+p.y_; return aa;}
Point operator-(Point  &p){Point aa; aa.x_=this->x_-p.x_; aa.y_=this->y_-p.y_; return aa;}
Point operator=(Point  &p){this->x_=p.x_; this->y_=p.y_; return *this;}
};


char * get_line(FILE *fp, int *err)
{
  int i = 0;
  int c;
  char *t;
  char *s = new char[1];
  while ((c = fgetc (fp)) != '\n' && c != EOF)
    {
      s[i] = c;
      i++;
      t = new char [i+1];
      for (int j = 0; j < i; j++)
        t[j] = s[j];
      delete [] s;
      s = t;
    }
  s[i] = '\0';
  if (i == 0 && c == EOF)
    {
      delete [] s;
      *err = 0;
      return  NULL;
    }
  if (c == EOF)
    {
      *err =  1;
    }

  *err = 2;
  return s;
}


Point* Get_fig(FILE* fp,int *nn)
{ 
  int* mas1=new int[0];
  int* mas2=new int[0];
  int flag, maf=1;
  Point* mp=new Point[0];
  int err=2, n,j,sch=0,tmp=0;
  char* l;
  l=get_line(fp,&err);
  //if(err!=2) return NULL;////////////////////////////////////////////////////////////////////////
  n=strlen(l);
  //cout<<n<<endl;
  if(n>0)
  {
  for(int i=0;i<n;i++)
 { //cout<<"now:  "<<i<<endl;
   tmp=0;
   j=i;
   flag=0;
   if(l[j]!=' ') flag=1;

   if(l[j]!=' '&& j+1<n){
   //cout<<"**"<<endl;flag=1;
   while(l[j]!=' '&& j<n) j++;
   j--;
}
   if(flag==1){
   if(l[i]=='-') {maf=-1; i++;}



   for(int k=i;k<=j;k++)
   {tmp += (l[k]-'0') * pow(10, k-i);}
   //cout<<tmp<<endl;
   sch++;
   for(int y=0;y<sch-1;y++) {mas2[y]=mas1[y];}
   delete[] mas1;
   mas1=new int[sch];
   for(int p=0;p<sch-1;p++)
   {
     mas1[p]=mas2[p];
   }
   mas1[sch-1]=tmp*maf;
   delete[] mas2;
   mas2=new int[sch];
   i=j;
   maf=1;
}
 }
  delete[] mas2;
 }
j=0;
 if (sch%2!=0) {cout<<"nechet"<<endl; return NULL;}
 mp=new Point[int(sch/2)];
 for(int i=0;i<sch-1;i++)
  { 
    mp[j].reset(mas1[i],mas1[i+1]);
    //(mp[j]).PPrint();
    j++;
    i++;
  }
*nn=sch/2;
delete[] mas1;
 return mp;
 }

void plp(Point* f,int n)
{
 for(int i=0;i<n;i++)
 {
   (f[i]).PPrint();
  // cout<<f[i].x()<<" "<<f[i].y()<<endl;
 }
}


double * append(double *massiv, double OP,int n) 
{
    double *temp = NULL;
    int numTemp = n + 1;
    temp=new double[numTemp];
     for (int kk = 0; kk < n; kk++)
    {
        temp[kk] = massiv[kk]; 
    }
    temp[n] = OP;  
    delete[] massiv; 
    return temp;
}





int cross(Point a, Point b, Point c, Point d)
{Point u,v1,v2;
     u.reset(a.x()-b.x(),a.y()-b.y());
     v1.reset(a.x()-c.x(),a.y()-c.y());
     v2.reset(a.x()-d.x(),a.y()-d.y());
    if ((u*v1)*(u*v2)>0)
         return 0;
    u.reset(d.x()-c.x(),d.y()-c.y());
    v1.reset(d.x()-a.x(),d.y()-a.y());
    v2.reset(d.x()-b.x(),d.y()-b.y());
    if ((u*v1)*(u*v2)>0)
         return 0;
        
    return 1;
}


//_________________________________________________________

/////////////////////////////////////////////////////////////////////////////////////////////////////     


int true_data(Point* k, int n)
{ int s, ss;
    for(int i=0;i<(n-1);i++){
        s=0;
        for (int j=0;j<(n-1);j++){
            if (cross(k[i],k[i+1],k[j],k[j+1])==1)
                s=s+1;}
                if (s>3)
                    return 0;}
    ss=0;
    for (int h=0;h<(n-1);h++)//проверяю для замыкания
        {
        if ((cross(k[n-1],k[0],k[h],k[h+1]))==1)
            ss=ss+1;
        if (ss>3)//тк в цикле я не дохожу до замыкающего ребра
                return 0;}
    return 1;
}







int inPolygon(Point *k1, Point* k,int n1,int n)//лежат ли точки к1 в к
{
    int c=0;
    int x, y;
    for(int j=0;j<n1;j++){
       x=k1[j].x();
       y=k1[j].y();
       for (int i=0;i<n;i++)
           if (((k[i].y()<=y && y<k[i-1].y()) || (k[i-1].y()<=y && y<k[i].y())) &&
               (x > (k[i-1].x() - k[i].x()) * (y - k[i].y()) / (k[i-1].y() - k[i].y()) + k[i].x())) c = c+1;
    }
    if (c==n1)    
       return 0;//один вложен в другой
    else
       return 1;
}







double max(int x, int y)
{
    if (x < y) {
        return y;
    }
    return x;
}

double min(int x, int y)
{
    if (x > y) {
        return y;
    }
    return x;
}


bool thc(int x, int y, int z, int w, double a, double b)//   2 0 0 2 -0.5  2.5
{
    //double k, c;

    if (z == x) 
    {//cout<<"!!!"<<endl;
        if (fabs(a-x)<=0.00001 && b >= min(y, w) && b <= max(y, w)) return 1;
        else return 0;
    }
    if (y==w)
    {//cout<<"!!"<<endl;
     if (fabs(b-y)<=0.00001 && a >= min(x, z) && a <= max(x, z)) return 1;
     else return 0; 
    }
//cout<<"            "<< ((a-x)*(w-y)- (b-y)*(z-x))<<endl;
if ( (  fabs((a-x)*(w-y)- (b-y)*(z-x))<=0.00001 && ((a<=x && z<=a) || (a<=z && x<=a)) )==1) {return 1;}
else return 0;

}

double point_otr(Point a, Point b, Point c)
{
double m1,m2;
if (fabs((a.y() - b.y()) * c.x() + (b.x() - a.x()) * c.y() + (a.x() * b.y() - b.x() * a.y())) <=0.00001) //3 points on one line
{
m1=pow((pow((c.x()-a.x()),2)+pow((c.y()-a.y()),2)),0.5);//расстояние до конца a
m2=pow((pow((c.x()-b.x()),2)+pow((c.y()-b.y()),2)),0.5);//расстояние до конца b
if(m1<m2) {/*cout<<"line "<<m1<<endl;*/ return m1;}
else {/*cout<<"line "<<m2<<endl; */return m2;}
}
double h;
double kof_x=a.y()-b.y();  //прямая a b
double kof_y=b.x()-a.x();
double kof=  a.x()*b.y()-a.y()*b.x();//коэффициенты в уравнении прямой, содержащей отрезок
double n_x=-kof_y;
double n_y=kof_x;//вектор нормальной прямой к ab
double n_c=-n_x*c.x()-n_y*c.y();
//ищем точку пересечения двух прямых
double p_x,p_y;
if(fabs(kof_x)<=0.00001) {p_x=c.x(); p_y=-kof/kof_y;}///
else if(fabs(kof_y)<=0.00001) {p_x=-kof/kof_x;p_y=c.y();}///
else {p_y=(kof*n_x-n_c*kof_x)/(n_y*kof_x-kof_y*n_x);    p_x=-(kof+kof_y*p_y)/kof_x;}

//cout<<"otrezok "<<a.x()<<" "<<a.y()<<" ____ "<<b.x()<<" "<<b.y()<<endl;
//cout<<"point "<<c.x()<<" "<<c.y()<<endl;
//cout<<"point of peresech "<<p_x<<" "<<p_y<<endl;
 if (thc(a.x(),a.y(),b.x(),b.y(),p_x,p_y)==1 )//точка перпендикуляра лежит на отрезке
                  { h=pow((pow((c.x()-p_x),2) + pow((c.y()-p_y),2)),0.5); //cout<<"*** "<<h<<" ***"<<" "<<p_x<<" "<<p_y<<endl;
                   return h;}
            else
                   {m1=pow((pow((c.x()-a.x()),2)+pow((c.y()-a.y()),2)),0.5);//расстояние до конца a
                   m2=pow((pow((c.x()-b.x()),2)+pow((c.y()-b.y()),2)),0.5);//расстояние до конца b
                   }

//cout<<"!!!"<<m1<<"___"<<m2<<endl;
if(m1<m2) return m1;
else return m2;                   
}




double super(Point *k1, Point* k2, int n1, int n2)//иду по точка к1, отрезки беру в к2
{//cout<<"___"<<n2<<"___"<<endl;
for(int i=0;i<n1-1;i++)
 for(int j=0;j<n2-1;j++)
 {if(cross(k1[i], k1[i+1], k2[j], k2[j+1])==1) return 0;}
double* ff=new double[0];
 double mm;
 int nn=0;
 for(int i=0;i<n1;i++)
    for(int j=0;j<n2-1;j++)
      {ff=append(ff,point_otr(k2[j],k2[j+1],k1[i]),nn);nn++;}

for(int i=0;i<n1;i++)
   {ff=append(ff,point_otr(k2[0],k2[n2-1],k1[i]),nn); nn++;}
mm=ff[0];
for(int i=0;i<nn;i++)
   if(ff[i]<mm) mm=ff[i];
return mm;
}


//__________________________________________________________
int main()
{/*
Point a(0,3);
Point b(3,2);
Point c(0.3,2.9);
bool rr=thc(0,3,3,2,0.3,2.9);
cout<<rr<<endl;
double ss=point_otr( a,  b, c);
cout<<ss<<endl;*/
  const int SIZE = 100;
  int n1=0,n2=0,flag=0;
  double t,t1,t2,r;
  FILE* fp;
  char q[SIZE];
  cout<<"Vvedite nazvaniye faila:"<<endl;
  cin>>q;
  fp=fopen(q, "r");
  Point* k1, *k2;
  k1=Get_fig(fp,&n1);
  k2=Get_fig(fp,&n2);
  if(k1==NULL || k2==NULL || n1*n2==0) {cout<<"data is bad"<<endl; return 0;}
  cout<<"1 polygon"<<endl;
  plp(k1,n1);
  cout<<"2 polygon"<<endl;
  plp(k2,n2);


if (true_data(k1,n1)*true_data(k2,n2)==0)
{
    cout<<"data is not correct"<<endl;
    flag=1;  
}


if (flag==0 && inPolygon(k1,k2,n1,n2)*inPolygon(k2,k1,n2,n1)==0)
{   
    flag=1;
    r=0;
    cout<<"one figure is contained in another figure"<<endl;
    cout<<"MIN: "<< r<<endl;
}

    
if (flag==0)
   {
   t2=super(k2,k1,n2,n1); //cout<<"t2"<<" "<<t2<<endl;
   t1=super(k1,k2,n1,n2); //cout<<"t1"<<" "<<t1<<endl;
   if(t1<t2)
       t=t1;
   else
       { t=t2;}

   cout<<"MIN: "<< t<<endl;
   }

fclose(fp);
return 0;
}
