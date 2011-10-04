int main()
{
    int n;
    int b,a = 1;
    int c = 0;
    printf("Enter which fibonacci number you want to print \n");
    scanf("%d",&n);
    
    if (n == 0 || n == 1)
       c = n;
    else
    {   
    
    while(n > 1)
    {
      b = a;      
      a = c;      
      c = a + b;      
      n--;
      printf("%d \t",c);
    }
}
    printf("%d",c);
    system("PAUSE");
    
}
