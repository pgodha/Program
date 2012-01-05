#include<stdio.h>
int atoi(char*);
void main()
{
	char str[20];
	int output;
	printf("Enter the string that you want to convert into integer");
	scanf("%s",str);
	output = atoi(str);
	printf("output %d",output);

}

int atoi(char* str)
{
	int output = 0;
	int i = 1;
	while(*str != '\0')
	{
		output = output*10 + (*str)-'0';
		str++;
	}
	return output;


}
