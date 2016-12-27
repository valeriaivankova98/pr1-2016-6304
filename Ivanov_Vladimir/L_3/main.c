#include <stdio.h>
#include <stdlib.h>
void print(char *s, int n); // функция для вывода
int main(){

    char* s=NULL;
    char c; //вводим переменную для посимвольного ввода  
    int nach= 0, kon= 0, n=0; // переменные для кол-ва предложений сначала и в конце, а также для определения длины каждого предложения
        while((c= getchar()) != '!') // условие, чтобы считывание закончилось на "!"
            {
                if (c=='\n' || c=='\t') n=0;
                else
                    switch(c){  
                        case '?': {n=0; nach++; break;} // если встречается "?", то обнуляем длину предложения и увеличиваем начальный счётчик
                        case '.': {print(s,n); printf("%c\n", c); nach++; kon++;n=0;break;} //если точка, то выводим массив, с записанными в него символами, ставим точку , увеличиваем счётчики и обнуляем длину
                        case ';': {print(s,n); printf("%c\n", c); nach++; kon++;n=0;break;}// тоже самое, что и с точкой
                        default: {n++;s=(char*)realloc(s,n*sizeof(char)); s[n-1]=c; break;}// придаём массиву длину, так чтобы в него мог вместиться следующий символ и не было лишних
                    }
            }


    printf("Количество предложений до %d и количество предложений после %d", nach, kon); // выводим ответ
    return 0;
} 
void print(char *s, int n)
{
    for (int i = (s[0] == ' ') ? 1 : 0; i < n; i++) //если сначала пробел, то печатаем не с 0, а с 1 символа
		printf("%c", s[i]);

}