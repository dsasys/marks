#include<stdio.h>
#include<unistd.h>

#define MAXCAPACITY 10 
#define LEAKRATE 1

int bucket = 0;

int main()
{


int incomingdata;

while(1)
{
printf("enter the amount of incoming data you wish to enter and press 0 to exit :");
if(scanf("%d" , &incomingdata) !=1  || incomingdata < 0)
{
printf("invalid user input so try again ");
while(getchar()!= '\n')
continue ;
}

bucket = (bucket + incomingdata > MAXCAPACITY) ? MAXCAPACITY : bucket + incomingdata ;
printf(" the data arrived is %d units , the current size is %d units \n " , incomingdata , bucket );
printf(" the data leaked is %d units , the current size is %d units \n " , LEAKRATE , bucket - LEAKRATE);


bucket = (bucket > LEAKRATE ) ? bucket - LEAKRATE : 0 ;

sleep(1);

}


printf("exit \n");

return 0 ;

}
