#include <iostream>
using namespace std;

char numero[10];

int main(){
    int nc;
    scanf("%d",&nc);
    while(nc--){
        scanf("%s",numero);
        if(strlen(numero)==5){
            printf("3\n");
        } else {
            if ((numero[0]=='o' && numero[1]=='n') || (numero[2]=='e' && numero[1]=='n') || (numero[0]=='o' && numero[2]=='e')) {
                printf("1\n");
            } else {
                printf("2\n");
            }
        }
    }
    
    return 0;
}