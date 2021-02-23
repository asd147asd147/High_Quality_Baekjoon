#include <stdio.h>

using namespace std;


int main(){
    char a, b;
    scanf("%c%c", &a,&b);
    do{
        printf("%c",a);
        a="", b="";
        scanf("%c%c", &a,&b);
    }while(a=="" && b=="");

	return 0;
}
