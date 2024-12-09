#include<stdio.h>
#include<string.h>

#define MAX 1024

void bitstuffing(const char *input , char *stuffed)
{
    int count = 0;
    int j = 0;
    
    
    for(int i = 0; input[i]!='\0' ; i++)
    { 
       stuffed[j++] = input[i];
    
    
    
    if(input[i] == '1')
    {
       count++;
    }
    
    else
    {
       count = 0;
    }
    
    
    if(count == 5)
    {
       stuffed[j++] = '0';
       count = 0;
     }
     
     }
   
   
   
   stuffed[j] = '\0';
}


void bitdestuffing(const char *stuffed , char *output)
{
    int count = 0;
    int j = 0;
    
    for(int i = 0; stuffed[i]!= '\0';i++)
    {
        output[j++] = stuffed[i];
    
    
    if(stuffed[i] == '1')
    {
       count ++;
    }
    
    
    else
    {
       count = 0;
    }
    
    if(count == 5 && stuffed[i+1] == '0')
    {
      i++;
      count = 0;
   }
   
  
}   output[j] = '\0';
 }
 
 
 
 int main()
 {
    char input[MAX];
    char stuffed[MAX];
    char destuffed[MAX];
    
    printf("enter the binary data :");
    scanf("%s", input);
    
    bitstuffing(input , stuffed);
    printf("%s\n", stuffed);
    
    bitdestuffing(stuffed , destuffed);
    printf("%s \n ",destuffed);
    
}
