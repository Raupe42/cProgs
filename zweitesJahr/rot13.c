/* author: Raupe

Task: C49A 2

ROT13 
*/

#include <stdio.h>

void rot13 (char s [])
{
    int i = 0;
   
    while (s [i] != '\0')
    {
        
        if (s [i] >= 'A' && s[i] < ('A' + 13))
            s [i] = (s [i] + 13);
        else if (s [i] >= ('A'+13) && s[i] <= 'Z')
            s [i] = (s [i] - 13);
    
        else if (s [i] >= 'a' && s[i] < ('a' + 13))
            s [i] = (s [i] + 13);
        else if (s [i] >= ('a'+13) && s[i] <= 'z')
            s [i] = (s [i] - 13);
       /*

        if (s [i] >= 'A' && s[i] <='M')
            temp [i] = (s[i] + 13);
        if (s[i] > 'M' && s[i] < 'Z')
            temp [i] = (s[i]- 13);

         if (s [i] >= 'a' && s[i] < ('a' + 13))
            temp [i] = (s [i] + 13);
        if (s [i] >= ('a'+13) && s[i] <= 'z')
            temp [i] = (s [i] - 13);
            */
        i ++;
    }
 //   s = temp;
}

int main (void)
{
    char str [100] = "Das ist das Haus vom Nikolaus";
    printf("%s\n", str);
    rot13 (str);
    printf("%s\n", str);
    rot13 (str);
    printf("%s\n", str);
}