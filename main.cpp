#include "userType.h"

int main(void)
{
	int jetton,color,point;
	userType user;
	
	printf ("请输入初始筹码数：");
	scanf ("%d",&jetton);
	user.setJetton(jetton);
	
	printf ("请输入盲注数：");
	scanf ("%d",&jetton);
	user.addJetton(-jetton);

	while (1) {
		int x;
		printf ("\n请选择决策（1更改最小押注 2增加牌  3修改筹码数  4获得决策）：");
		scanf ("%d",&x);
		if  (x==1) {
			printf ("\n输入最小押注数\n");
			scanf ("%d",&jetton);
			user.setMinBet(jetton);
		}
		if  (x==2){
			printf ("\n1黑桃 2红桃 3梅花 4方片\n");
			scanf ("%d%d",&color,&point);
			user.addPoker(color,point);
		}
		if  (x==3) {
			printf ("\n输入当前的筹码数\n");
			scanf ("%d",&jetton);
			user.addJetton(jetton);
		}
		if  (x==4) {
			int action = user.getAction();
			if  (action==0){
				printf ("让牌\n");
			}
			else if  (action==-1){
				printf ("跟注\n");
			}
			else if  (action==-2){
				printf ("全押\n");
			}
			else if  (action==-3){
				printf ("弃牌\n");
			}
			else{
				printf ("加注%d\n",action);
			}
		}
	}
	//user.display();
	//printf ("%d\n",user.getAction());
	
	return 0;
}