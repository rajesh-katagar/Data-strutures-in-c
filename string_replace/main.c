#include <stdio.h>

typedef struct txt{
    char str[100];
}text;

int count(char str[100]){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}

int read(text *tptr, FILE *fp){
    int n_lines=0;
    while(!feof(fp)){
        fgets(tptr->str, 40, fp);
        tptr++;
        n_lines++;
    }
    return n_lines;
}

void display(text *tptr, int n){
    for(int i=0; i<n; i++){
        printf("%s", tptr->str);
        tptr++;
    }
}

int longest(text *tptr, int n){
    int lengths[10];
    int c;
    for(int i=0; i<n; i++){
        c = count(tptr->str);
        lengths[i]=c;
        tptr++;
    }

    int max=0,m;
    for(int j=0; j<n; j++){
        if(lengths[j]>max){
            max = lengths[j];
            m=j;
        }
    }

    return m;
}

int main(){
    text *tptr;
    FILE *fp;
    fp = fopen("lines.txt", "r+");

    int n_lines, l;
    n_lines = read(tptr,fp);

    display(tptr,n_lines);

    l = longest(tptr,n_lines);

    printf("The longest line is : \n");
    for(int i=0; i<l; i++)
    {
        tptr++;
    }
    printf("%s", tptr->str);

    fprintf(fp, "%s", tptr->str);

    return 0;
}