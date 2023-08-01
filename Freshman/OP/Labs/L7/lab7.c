#include <stdio.h>

int count_word(char c, char last);
int count_cntr(char c);
int count_lat(char c);
int count_digit(char c);
int count_lines(char c);
int count_op(char c);
void out(char s[], int a[]);

int main()
{
    int c;
    int a[7] = {0, 0, 0, 0, 0, 0, 0}; // 0 - символы, 1 - строки, 2 - слова, 3 - упр. символы, 4 - лат. алфавит, 5 - цифры, 6 - знаки операций
    char s[2048], last = ' ';
    printf("Enter some text:\n");
    while ((c=getchar())!=EOF){
		if (a[0] == 2048){
			printf("\033[31mWARNING! \033[97mExceeded the number of characters for output (default - 2048). Emergency termination!\n");
			break;		
		} 
        s[a[0]] = c;
        a[0]+=1;
        a[1]+=count_lines(c);
        a[2]+=count_word(c, last);
        a[3]+=count_cntr(c);
        a[4]+=count_lat(c);
        a[5]+=count_digit(c);
        a[6]+=count_op(c);
        last = c;
    }
    out(s, a);
}

int count_lines(char c){
	return (c == '\n');
}

int count_word(char c, char last){
	int x1 = (last == '\t') || (last == ' ') || (last == '\n');
	int x2 = (c != ' ') && (c != '\t') && (c != '\n');
	return x1 && x2;
}

int count_cntr(char c){
	return ((c >= 0 && c <= 31) || c == 127);
}

int count_lat(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int count_digit(char c){
	return (c >= '0' && c <= '9');
}


int count_op(char c){
	return (c == '+' || c == '-' || c == '%' || c == '/');
}

void out(char s[], int a[]){
    printf("\n\033[33mResults:\n\n");
    printf("\033[92mSource text:\033[97m\n\n");
    for(int i = 0; i < a[0]; i++)
        putchar(s[i]); // посимвольный вывод текста
    printf("\n\033[92mCharacters \033[97m- %d\n\033[92mLines \033[97m- %d\n\033[92mWords \033[97m- %d\n", a[0],a[1],a[2]);
    printf("\033[92mControl characters \033[97m- %d\n\033[92mLatin letters \033[97m- %d\n\033[92mDigits \033[97m- %d\n\033[92mOperations \033[97m- %d\n", a[3],a[4],a[5],a[6]);
}
