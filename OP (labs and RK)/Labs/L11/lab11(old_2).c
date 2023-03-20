#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 4096
typedef struct list
{
    char *string;
    struct list *next;
} WORD;



WORD * init(WORD *p, char *line){
  char *elem;
  elem = (char *)malloc(strlen(line));
  strcpy(elem, line);
  p->string = elem;
  p->next = 0;
  return p;
}

int lat(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void add(WORD *press, char *line){
  WORD *tmp = (WORD*)malloc(sizeof(WORD));
  char *elem;
  elem = (char *)malloc(strlen(line));
  strcpy(elem, line);
  tmp->string = elem;
  tmp->next = 0;
  while (press -> next != 0){
    press = press -> next;
  }
  press->next = tmp;
}

void in(WORD * press){
	char line[LINE_LEN]={'\0'}, c;
	int j = 0, count = 0;
    while((c=getchar())!=EOF){
		if ((c != ' ') && (c != '\t') && (c != '\n')){
			if(lat(c)){
				line[j++] = c;
			}
		} else{
			line[j] = '\0';
			j = 0;
			if (strlen(line)==0) continue;
			if (count == 0){
				press = init(press, line);
				count++;
			} else{
				add(press, line);    
			}
		}
	}
}

void out(WORD *press){
	while(press != 0){
    printf("%s\n", press->string);
    press = press->next;
  }
}
int main(){
  WORD *press = (WORD *)malloc(sizeof(WORD));
  in(press);
  printf("\n");
  out(press);
}
