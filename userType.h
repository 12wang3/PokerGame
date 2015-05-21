#include "checkString.h"

class userType
{
	public:
		userType();
		~userType();

		void setJetton(int m);//���ó�����
		void addJetton(int m);//����m������
		void setMinBet(int minBet);//������СѺע��
		int  getAction();//��þ���
		void addPoker(int color,int point);//���һ����
		void addPoker(char *colorString,int point);//���һ����
		void display();
	private:
		int jetton;//���ճ�����
		int minBet;//��С������
		pokerStringType pokerString;
};

userType::userType()
{
	jetton=0;
	minBet=0;
}

userType::~userType()
{
}

void userType::setJetton(int m)
{
	jetton=m;
}
void userType::addJetton(int m)
{
	jetton+=m;
}
void userType::setMinBet(int m)
{
	minBet=m;
}
void userType::addPoker(int color,int point)
{
	pokerString.addPoker(color,point);
}
void userType::addPoker(char *colorString,int point)
{
	pokerString.addPoker(colorString,point);
}
void userType::display()
{
	printf ("{%d}{%d}\n",jetton,minBet);
	printf ("<<%d>>\n",pokerString.calcValue());
	pokerString.display();
}
int userType::getAction()
{
	int value=pokerString.calcValue();
	if  (value >=4) {
		if  (jetton>0) {
			jetton=0;
			return -2;
		}
		else {
			return 0;
		}
	}
	if  (value==3) {
		if  (jetton>0) {
			if  (minBet>jetton) {
				jetton=0;
				return -2;
			}
			else{
				if  (minBet*1.5<jetton){
					jetton-=minBet*1.5;
					return minBet*1.5;
				}
				else{
					jetton=0;
					return -2;
				}
			}
		}
		else {
			return 0;
		}
	}
	if  (value==2) {
		if  (jetton>0) {
			if  (minBet>jetton) {
				jetton=0;
				return -2;
			}
			else{
				if  (minBet*1.2<jetton){
					jetton-=minBet*1.2;
					return minBet*1.2;
				}
				else{
					jetton=0;
					return -2;
				}
			}
		}
		else {
			return 0;
		}
	}
	if  (value==1) {
		if  (jetton>0) {
			if  (minBet>jetton*0.3) {
				if  (pokerString.getTot()<=4)
					return -3;
				else 
					if  (minBet>jetton) {
						jetton=0;
						return -2;
					}
					else{
						return -3;
					}
			}
			else{
				jetton-=minBet;
				return -1;
			}
		}
		else {
			return 0;
		}
	}
	if  (value==0) {
		if  (pokerString.getTot()>=4) {
			return -3;
		}
		else if (pokerString.getTot()<=2) {
			if  (minBet<jetton*0.2) {
				jetton-=minBet;
				return -1;
			}
			else{
				return -3;
			}
		}
		else{
			if  (minBet<jetton*0.1) {
				jetton-=minBet;
				return -1;
			}
			else{
				return -3;
			}
		}
		return 0;
	}
}