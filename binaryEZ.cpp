#include <stdio.h>

int main(){
    int bin[100];
	int numbin;
	int dec;
	
	printf("Input decimal :");
	scanf("%d",&dec);
	
	for(int i = 0 ;dec > 0 ; i++){
        if(dec %2 == 0)         
            bin[numbin] = 0;
        else
            bin[numbin] = 1;
        dec /= 2;
        numbin++;
    }
    while (numbin%4 != 0){
        bin[numbin] = 0;
        numbin++;
    }
    printf("Binary is ");
    for (int i = numbin-1; i>=0; i--) {   // (mumbin-1) because numbin = 4 but indexArray 0 1 2 3  NO have 4 
        printf("%d", bin[i]); 
    }
    return 0;
}
