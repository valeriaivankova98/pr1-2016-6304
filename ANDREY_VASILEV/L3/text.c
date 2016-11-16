#include<stdio.h>
#include<string.h>
void vvod(char* input, int* index, int* pered, int* posle)  //Передаем в функцию указатель на строку символов(ввод)
{														    //указатель на массив целых чисел(вспомогат.) и указатели 
	int i=0, k=1;											//на целые, в которые запишем количество предложений до и
	index[0] = 0;										    //после
	*pered = 0;	
	*posle = 0;
	char ch;
	while((ch=getchar()) != '!'){						  //Заполняем массив посимвольно, пока не будет введен символ !
		input[i] = ch;									  
		if (input[i]==';'||input[i]=='.'||input[i]=='?'){ //Если введенный символ это разделитель(;.?) то счетчик 
			(*pered)++;									  //предложений "до" увеличивается на 1.
			index[k++]=i+1;        						  //В данной строке, если выполнено условие сверху, заполняется
		} 												  //массив целых значениями(номер разделителя), с помощью 
		i++;											 //которых можно будет разделить текст на отдельные предложения 
	}													  
	input[index[k-1]] = '\0';							  //После последнего разделителя ставим символ конца строки для
	for(i=0; i<strlen(input); i++){						  //того, чтобы определить длину введеного текста.
		if (input[i]=='?') (*posle)++;					  //Поиск с помощью цикла в введеном тексте символа ? При  
	}													  //нахождении увеличиваем счетчик на 1. В итоге получим 
	*posle= (*pered)-(*posle);							  //разность между количеством предложений "до" и "после"
}

void redact(char* input, int* index,int pered, char output[500][1000]) //Передаем в функцию введеный текст, количество 
{																	   //предложений "до" и двумерный символьный массив,
	int k =0, e = 0, i;												   //который заполним отформатированными предл.
	for (k = 0; k<pered; k++){										   //Цикл заполнения двумерного массива:
		i = 0;														   //Если символ следующего разделителя (к+1) это ?
		if (input[index[k+1]-1]=='?'){								    //то мы переходим к следущей строке и следующему
				continue;											    //разделителю.
		}															   //Если условие не выполнено, то:
		e = index[k];												     //Присваиваем "е" значение номера разделителя и 
		while(input[e] == '\n' || input[e]=='\t'||input[e]==' ') e++;    //с помощью цикла проверяем является ли символ
		for(e; e<index[k+1]; e++){									     //для данного "е" пробелом, '\t' или '\n' 
			output[k][i++]=input[e];								     //Когда "е" примет значение какой-то буквы 
			output[k][i] = '\0';									     //данная строка двумерного массива начнет 
		}															     //заполнятся. Последний символ  - конец строки.
        printf("%s\n", output[k]);									     //Печатаем данную строку.
	}																   //
			
}
