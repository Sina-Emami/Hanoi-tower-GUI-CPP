#include <graphics.h>
#include <conio.h>
#include <iostream>

#define YSize 20
using namespace std;
int n,DELAY=100,flag=1;
int DiskIsIn[5], PIP[5], DiskCount[3];

void DrawHanoi(int );
void Towers(int ,int ,int ,int );
void MoveDisk(int ,int , int );

int main(){
	int i;
	do{
            cout<<"Enter Number of Disks Between(1-5) = ";
		    cin>>n;
    }while((n<1)&&(n>5));

	initwindow(800,600);
	cleardevice();
	setcolor(WHITE);
	outtextxy(70,300,"SHAFT 0");
	outtextxy(290,300,"SHAFT 1");
	outtextxy(510,300,"SHAFT 2");
	DiskCount[0]=n;
	DiskCount[1]=0;
	DiskCount[2]=0;
	for(i=0;i<n;i++)
    {
        PIP[i]=i;
        DiskIsIn[i]=0;
    }
              DrawHanoi(n);
	Towers(n,0,2,1);
	getch();
	closegraph();
	return 0;
}

void DrawHanoi(int n)
{
	int i,x,y,size;
	for(i=0;i<n;i++)
    {
		x=5+((4-i)*20);
		y=150+PIP[i]*30;
		size=40+i*40;
		setfillstyle(SOLID_FILL,i);
		bar(x,y,x+size,y+YSize);
	}
}

void Towers(int n,int A,int C,int B)
{
	if(n==1)
    {
		MoveDisk(1,A,C);
		cout<<A<<" -> "<<C<<endl;
		return;
	}
	Towers(n-1,A,B,C);
	cout<<A<<" -> "<<C<<endl;
	MoveDisk(n,A,C);
	Towers(n-1,B,C,A);
}

void MoveDisk(int DiskN,int A, int C)
{
	int x,y,size=DiskN*40,positionx,positiony;
	x=5+(DiskIsIn[DiskN-1]*215)+((5-DiskN)*20);
	y=150+PIP[DiskN-1]*30;
	do{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
		y-=30;
		setfillstyle(SOLID_FILL,5+DiskN);
		bar(x,y,x+size,y+YSize);
		delay(DELAY);
	}while(y>50);

	positionx=5+(C*215)+((5-DiskN)*20);
	do{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
		if(positionx<x)
        {
            x-=43;
        }
        else
        {
            x+=43;
        }
		setfillstyle(SOLID_FILL,5+DiskN);
		bar(x,y,x+size,y+YSize);
		delay(DELAY);
	}while(x!=positionx);

	PIP[DiskN-1]=n-1-DiskCount[C];
	DiskCount[C]++;
	DiskCount[A]--;
	DiskIsIn[DiskN-1]=C;

	positiony=150+PIP[DiskN-1]*30;
	do{
		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+size,y+YSize);
		y+=30;
		setfillstyle(SOLID_FILL,5+DiskN);
		bar(x,y,x+size,y+YSize);
		delay(DELAY);
	}while(y<positiony);
}
