#include <stdio.h>
int main()
{   
    int cs;
    while((cs = getchar()) != '\n')
    {
    	switch(cs - '2')
    	{
    		case 0:
    		case 1:
    			putchar(cs + 4);
    		case 2:
    			putchar(cs + 4);
    			break;
    		case 3:
    			putchar(cs + 3);
    		default:
    			putchar(cs + 2);
    	}
    }
    return 0;
}
