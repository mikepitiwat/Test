#include<stdio.h>

int main(){
	int scoreSTD[100]; // score of student
	int score;
	int num = 0;
	
	// input score
	do{
		printf("Enter score stdent[%d]: ",num+1);
		scanf("%d",&score);
		scoreSTD[num] = score;
		num++;
	}while(score != -1);
	
	// show score
	for(int i = 0; i<num-1; i++){
		printf("\nStudent[%d] scores is %d\n",i+1,scoreSTD[i]);
	}
	
	
	
}
