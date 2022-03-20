#include <stdio.h>
#include <cs50.h>
#include <math.h>

long digit(long num, int n)
{
    long r;
    r = num / pow(10, n);
    r = r % 10;
    return r;
}

long length(long num){
    long n = floor(log10(num))+1;
    return n;
}


bool checksum(long num){
    
    long len = length(num);
    long check = 0;
    
    
    if (len != 16)
    {
    for(long i=1; i<len-1; i+=2){
        
        
        for(int j=0; j<length(digit(num,i)*2); j++){
            check+=digit((digit(num,i)*2),j);
        }
     }
     
     
    
    
    for(int i=0; i<len; i+=2){
        check+=digit(num,i);
    }
    } else
    {
        
     for(long i=len-1; i>0; i-=2){
        
        
        for(int j=0; j<length(digit(num,i)*2); j++){
            check+=digit((digit(num,i)*2),j);
        }
        
     }
     
      for(int i=len; i>=0; i-=2){
        check+=digit(num,i);
    }
    
    }
    
    
    
    // if(len==16)
    // {
       
    // } else 
    // {
    //     for(int i=len; i>0; i-=2){
    //     check+=digit(num,i);
    // }
    // }
    
    printf("Checksum: %li\n",check);
    if(check%10 == 0) return true;
    return false;
    
    
}

int main (void)
{

    
    long x = get_long("Number: ");
    // printf("%li\n",digit(x,15));
    // printf("%li\n",length(x));
    
    long len = length(x);
    if(len>=13 & len<=16)
    {
    if(checksum(x)) 
    {
        if(len == 15) // AMEX check
        {
            if((digit(x,len-1) == 3 && digit(x,len-2) == 4) || (digit(x,len-1) == 3 && digit(x,len-2) == 7))
            {
                printf("AMEX\n");
            } else printf("INVALID\n");
            
        } else if (len == 13) // VISA 13 check
        {
            if (digit(x,len-1) == 4)
            {
                printf("VISA\n");
            } else printf("INVALID\n");
        } else if (len == 16)
        {
            if (digit(x,len-1) == 4) 
            {
                printf("VISA\n"); // VISA 16 check
            }
            else if (digit(x,len-1) == 5) // MASTERCARD check
            {
                if ((digit(x,len-2) == 1) || (digit(x,len-2) == 2) || (digit(x,len-2) == 3) || (digit(x,len-2) == 4) || (digit(x,len-2) == 5)) 
                {
                    printf("MASTERCARD\n");
                } else printf("INVALID\n"); 
            
        } else printf("INVALID\n");
    } else printf("INVALID\n");
    
} else printf("INVALID\n");
} else printf("INVALID\n");


}