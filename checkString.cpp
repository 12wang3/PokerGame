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
	for (int i=tot;i>=2&&((poker[i].point<poker[i-1].point)||(poker[i].point==poker[i-1].point&&poker[i].color<poker[i-1].color));i--) {
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
int pokerStringType::calcValue()
{
	int i,j;
	int value=0;
	
	if  (tot==5) {
		for (j=1;j<=tot-4;j++){//判断是否为同花顺,或同花或顺子
			int v=0;
			int s=1,o=1;
			for (i=j+1;i<=j+4;i++) {
				//printf ("{%d,%d}",j,i);
				if  (poker[i].color!=poker[i-1].color) {
					s=0;
				}
				if  (poker[i].point!=poker[i-1].point+1) {
					o=0;
				}
			}
			if  (s&&o) {v=8;}
			else if(s) {v=5;}
			else if(o) {v=4;}
			if  (v>value) {
				value=v;
			}
		}
		if  (value!=0)
			return value;
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
void pokerStringType::display()
{
	for (int i=1;i<=tot;i++) {
		printf ("[%d,%d] ",poker[i].color,poker[i].point);
	}
	printf ("\n");
}


int main(void)
{
	pokerStringType pst;
	pst.addPoker(4,1);
	pst.addPoker(4,8);
	pst.addPoker(4,1);
	pst.addPoker(2,7);
	pst.addPoker(4,2);
	pst.addPoker(5,7);
	pst.addPoker(4,8);
	pst.display();
	printf ("%d\n",pst.calcValue());
	return 0;
}