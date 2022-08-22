static int i = 0;
void reverse (char *s){
    char temp;
        if (*(s+i) != '\0'){
            i++;
            reverse (s);
        }
        else 
            i = 0;
    *(s+i)= temp;
    i++;
}