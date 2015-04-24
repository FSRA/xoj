#include <cstdio>

int main()
{
        char inp;
        int i = 0;
        while (scanf("%c", &inp) != EOF)
        {
                if ((inp >= 'A') && (inp <= 'Z'))
                {
                        inp = ((inp - 'A') - i+26) % 26 + 'A';
                }
                else if ((inp >= 'a') && (inp <= 'z'))
                {
                        inp = ((inp - 'a') - i+26) % 26 + 'a';
                }
                i=(i+1)%26;
                printf("%c", inp);
        }
        return 0;
}
