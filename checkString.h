#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

class pokerStringType//定义存放一个牌组的信息的类
{
	public:
		struct pokerType//定义存放一张牌的信息的结构体
		{	
			int color;/*牌的颜色编号	SPADES   1
									HEARTS   2
									CLUBS    3
									DIAMONDS 4*/
			int point;//牌的点数2到14
		};

		pokerStringType();
		~pokerStringType();
		
		void addPoker(char *colorString,int point);//添加一张牌,并保证牌组点数为升序
		void addPoker(int color,int point);//同为添加，但是花色直接为编号
		int getTot();//获得牌组的牌的张数
		int calcValue();/*计算这组牌能组成的最好的牌的价值
						  8 同花顺
						  7 四条
						  6 葫芦
						  5 同花
						  4 顺子
						  3 三条
						  2 两对
						  1 一对
						  0 高牌*/
		void display();//输出牌组
	private:
		int tot;//牌总数
		pokerType poker[9];//牌组

		int calcFive(pokerType *p); //计算长度为五的牌组的最好的牌的价值

};

pokerStringType::pokerStringType()
{
	tot=0;
}
pokerStringType::~pokerStringType()
{

}
void pokerStringType::addPoker(int color,int point)
{
	tot++;
	poker[tot].point=point;
	poker[tot].color=color;
	pokerType tmp;
	for (int i=tot;i>=2&&(poker[i].point<poker[i-1].point);i--) {
		tmp=poker[i];
		poker[i]=poker[i-1];
		poker[i-1]=tmp;
	}
}
void pokerStringType::addPoker(char *colorString,int point)
{
	int color;
	switch(colorString[0]) {
		case 'S':color=1;break;
		case 'H':color=2;break;
		case 'C':color=3;break;
		case 'D':color=4;break;
	}
	addPoker(color,point);
}
int pokerStringType::calcFive(pokerType *p)
{
	int i;
	int value=0,v=0;
	int s=1,o=1;
	for (i=2;i<=5;i++) {
		//printf ("{%d,%d}",j,i);
		if  (p[i].color!=p[i-1].color) {
			s=0;
		}
		if  (p[i].point!=p[i-1].point+1) {
			o=0;
		}
	}
	if  (s&&o) {v=8;}
	else if(s) {v=5;}
	else if(o) {v=4;}
	if  (v>value) {
		value=v;
	}
	return value;
}
int pokerStringType::calcValue()
{
	int i,j,len=0;
	int value=0,v=0;
	pokerType tmp[7];
	if  (tot==5) {
		value=calcFive(poker);
		if  (value>0) {
			return value;
		}
	}
	if  (tot==6) {
		for (i=1;i<=tot;i++) {
			len=0;
			for (j=1;j<=tot;j++) {
				if  (i!=j) {
					len++;
					tmp[len]=poker[j];
				}
			}
			v=calcFive(tmp);
			if  (v>value) {
				value=v;
			}
		}
		if  (value>0) {
			return value;
		}
	}
	int cnt=0;
	int count[5]={0};
	for (i=1;i<=tot+1;i++) {
		if  (poker[i].point!=poker[i-1].point) {
			count[cnt]++;
			cnt=1;
		}
		else{
			cnt++;
		}
	}
	for (i=1;i<=4;i++) {
		printf ("[%d,%d]\n",i,count[i]);
	}
	if  (count[4]>=1) {
		return 7;
	}
	if  (count[3]>=1&&count[2]>=1) {
		return 6;
	}
	if  (count[3]>=1) {
		return 3;
	}
	if  (count[2]>=2) {
		return 2;
	}
	if  (count[2]>=1) {
		return 1;
	}
	return 0;
}
int pokerStringType::getTot()
{
	return tot;
}
void pokerStringType::display()
{
	for (int i=1;i<=tot;i++) {
		printf ("[%d,%d] ",poker[i].color,poker[i].point);
	}
	printf ("\n");
}
