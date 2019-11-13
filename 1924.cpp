#include <stdio.h>

void print(int y){
		switch(y % 7){
			case 0:
				printf("SUN");
				break;
			case 1:
				printf("MON");
				break;
			case 2:
				printf("TUE");
				break;
			case 3:
				printf("WED");
				break;
			case 4:
				printf("THU");
				break;
			case 5:
				printf("FRI");
				break;
			case 6:
				printf("SAT");
				break;
		}
}


int main(){
	
	int x,y;
	
	scanf("%d %d", &x, &y);
	
	if(x == 1){
		print(y);
	}
	
	else if(x == 2){
		print(y + 3);
	}
	
	else if(x == 3){
		print(y + 3);
	}

	else if(x == 4){
		print(y + 6);
	}
	
	else if(x == 5){
		print(y + 1);
	}
	
	else if(x == 6){
		print(y + 4);
	}
	
	else if(x == 7){
		print(y + 6);
	}
	
	else if(x == 8){
		print(y + 2);
	}
	
	else if(x == 9){
		print(y + 5);
	}
	
	else if(x == 10){
		print(y);
	}
	
	else if(x == 11){
		print(y + 3);
	}	
	
	else if(x == 12){
		print(y + 5);
	}
	
}
