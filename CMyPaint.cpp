#include "CMyPaint.h"


double cosinus(point a,point L)
{
	double coss = (a.x*L.x + a.y*L.y + a.z*L.z)/(2*sqrt(a.x*a.x + a.y*a.y + a.z*a.z)*sqrt(L.x*L.x + L.y*L.y + L.z*L.z));
	return coss;
}
double dist(point a,point L)
{
	double d = sqrt((a.x-L.x)*(a.x-L.x) + (a.y-L.y)*(a.y-L.y) + (a.z-L.z)*(a.z-L.z));
	return d;
}
void CMyPaintDC::AreaGuro(light L,double kd,point a,point b,point c,int Cr,int Cg,int Cb)
{   
 double Ia, Ib, Ic;
 double I1,I2,I;
 
 double y,x;
 double x1,x2,t1,t2,t;
 int R,G,B;
 const double K = 1; //произвольная постоянная

 if(a==b&&a==c)return;

 //упорядочить вершины по y
 {	point temp;
	if(a.y>b.y)
	{temp=a;
	 a=b;
	 b=temp;
	}
	if(b.y>c.y)
	{temp=b;
	 b=c;
	 c=temp;
	}
	if(a.y>b.y)
	{temp=a;
	 a=b;
	 b=temp;
	}
 }
 //Sleep(500);
 Ia = (L.I*kd*cosinus(a,L.C)/(dist(a,L.C) + K))*100;
 Ib = (L.I*kd*cosinus(b,L.C)/(dist(b,L.C) + K))*100;
 Ic = (L.I*kd*cosinus(c,L.C)/(dist(c,L.C) + K))*100;

 //закрашиваем линии от верхней к нижней
 for(y=a.y;y<b.y;y++)
 {
	 //точки пересечения линии(y) с границами грани(ac,ab)
	 x1 = ((y-a.y)/(b.y-a.y))*(b.x-a.x) + a.x;
	 x2 = ((y-a.y)/(c.y-a.y))*(c.x-a.x) + a.x;

	 //интенсивности в точках пересечения линии(y) с границами грани
	 if(a.x==b.x)continue;
	 if(a.x==c.x)continue;
	 t1 = (x1-b.x)/(a.x-b.x);
	 t2 = (x2-c.x)/(a.x-c.x);
	 I1=t1*Ia + (1-t1)*Ib;
	 I2=t2*Ia + (1-t2)*Ic;

	 if(x2==x1)continue;
	 if(x2>x1)
	 {
		//рисовать линию
		for(x = (int)x1;x<=(int)x2;x++)
		{
		//интенсивность в точке x
		t = (x2-x)/(x2-x1);
		I = t*I1 + (1-t)*I2;
		//поставить точку
		//if(I>1)I=1;
		//if(I<0)I=0;
		R = int(Cr*I);
		G = int(Cg*I);
		B = int(Cb*I);
		if(R>255)R=255;
		if(R<0  )R=0;
		if(G>255)G=255;
		if(G<0  )G=0;
		if(B>255)B=255;
		if(B<0  )B=0;
		/*if(R==0&&G==0&&B==0)
			MessageBox(NULL,"от он, пиксель!",NULL,MB_OK);*/
		mydc->SetPixelV(int(x),int(y),RGB(R,G,B));
		//Sleep(1);
		}
	 }
	 else 
	 {
		//рисовать линию
		for(x = (int)x1;x>=(int)x2;x--)
		{
		//интенсивность в точке x
		t = (x2-x)/(x2-x1);
		I = t*I1 + (1-t)*I2;
		//поставить точку
		//if(I>1)I=1;
		//if(I<0)I=0;
		R = int(Cr*I);
		G = int(Cg*I);
		B = int(Cb*I);
		if(R>255)R=255;
		if(R<0  )R=0;
		if(G>255)G=255;
		if(G<0  )G=0;
		if(B>255)B=255;
		if(B<0  )B=0;
		/*if(R==0&&G==0&&B==0)
			MessageBox(NULL,"от он, пиксель!",NULL,MB_OK);*/
		mydc->SetPixelV(int(x),int(y),RGB(R,G,B));
	//	Sleep(1);
		}
	 }
	 //Sleep(50);
 }
 for(y=b.y;y<=c.y;y++)
 {
	 //точки пересечения линии(y) с границами грани(ac,bc)
	 x1 = ((y-b.y)/(c.y-b.y))*(c.x-b.x) + b.x;
	 x2 = ((y-a.y)/(c.y-a.y))*(c.x-a.x) + a.x;

	 //интенсивности в точках пересечения линии(y) с границами грани
	 if(c.x==b.x)continue;
	 if(a.x==c.x)continue;
	 t1 = (x1-c.x)/(b.x-c.x);
	 t2 = (x2-c.x)/(a.x-c.x);
	 I1=t1*Ib + (1-t1)*Ic;
	 I2=t2*Ia + (1-t2)*Ic;

	 if(x2==x1)continue;
	 if(x2>x1)
	 {
		//рисовать линию
		for(x = (int)x1;x<=(int)x2;x++)
		{
		//интенсивность в точке x
		t = (x2-x)/(x2-x1);
		I = t*I1 + (1-t)*I2;
		//поставить точку
		//if(I>1)I=1;
		//if(I<0)I=0;
		R = int(Cr*I);
		G = int(Cg*I);
		B = int(Cb*I);
		if(R>255)R=255;
		if(R<0  )R=0;
		if(G>255)G=255;
		if(G<0  )G=0;
		if(B>255)B=255;
		if(B<0  )B=0;
		/*if(R==0&&G==0&&B==0)
			MessageBox(NULL,"от он, пиксель!",NULL,MB_OK);*/
		mydc->SetPixelV(int(x),int(y),RGB(R,G,B));
		//Sleep(1);
		}
	 }
	 else
	 {
		//рисовать линию
		for(x = (int)x1;x>=(int)x2;x--)
		{
		//интенсивность в точке x
		t = (x2-x)/(x2-x1);
		I = t*I1 + (1-t)*I2;
		//поставить точку
		//if(I>1)I=1;
		//if(I<0)I=0;
		R = int(Cr*I);
		G = int(Cg*I);
		B = int(Cb*I);
		if(R>255)R=255;
		if(R<0  )R=0;
		if(G>255)G=255;
		if(G<0  )G=0;
		if(B>255)B=255;
		if(B<0  )B=0;
		/*if(R==0&&G==0&&B==0)
			MessageBox(NULL,"от он, пиксель!",NULL,MB_OK);*/
		mydc->SetPixelV(int(x),int(y),RGB(R,G,B));
		//Sleep(1);
		}
	 }
	 //Sleep(50);
 }
}

void CMyPaintDC::PaintSideGuro(point side[],int n,light L,double kd,int Cr,int Cg,int Cb)
{
 for(int i=1;i<n-1;i++)
 {
	 AreaGuro(L,kd,side[0],side[i],side[i+1],Cr,Cg,Cb);
 }
 return;
}