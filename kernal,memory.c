#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(){
int a;
	printf("\nKernel version:\n");
	system("cat /proc/sys/kernel/osrelease");
	printf("\nConfigured free and used memory:\n");
	system("cat /proc/meminfo|awk 'NR==1,NR==2{print}'");
	return 0;
}
