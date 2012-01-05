#include<stdio.h>
#include<malloc.h>
void ItoA(int,char*);
void reverse(char*, int);
void main()
{
	int input;
	char* output =(char*) malloc(sizeof(20));
	printf("Enter the integer you want to convert into string\n");
	scanf("%d",&input);
//	printf("hi");
	ItoA(input,output);
//	printf("hi");
	printf("%s",output);
}

void ItoA(int i, char* str)
{			
	//char* str = (char*)malloc(4*sizeof(char));
	int j;
	int k = 0;
	if(i < 0)
	{
		str[k++] ='-';
		i = -i;
	}
	while(i != 0)
	{
//		printf("hi");
		j = i%10; 
		str[k++] = (char)j + 48;
		i = i/10;
	}
	str[k+1] = '\0';
//	printf("hi");
	printf("what-->%s",str);
	reverse(str,k+1);

}

void reverse(char* str, int len)
{
	int i;
	char temp;
	for (i = 0;i<len/2;i++)
	{
		temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
}
		
		



