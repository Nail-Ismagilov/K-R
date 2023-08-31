/*
 * The file contains examples and exercises from K&R 
 * "The C Proggramming languages" book. Chapter 6.3
 * "Arrays of Structure".
 */

#define NKEYS   100

int main(){

    /* Consider writint a program to count the occurences of each C keyword.
    * We need an array of character strings to hold the names and array of integers to count.
    * */

    // char *keyword[NKEYS];
    // int keyword[NKEYS];

    /* But the fact that thu arrays are parallel suggests a different organization, an array of structure.
     * Each keyword entry is a pair:
     *
     *  char *word;
     *  int count
     */

    // struct key{
    //     char *word;
    //     int count;
    // } keytab[NKEYS];
   
   
   /* declares a structure type key, defines an array keytab of structures of this
    * type, and sets aside storage for them. Each element of the array is a structure.
    * 
    * */

    struct key {
        char * word;
        int count;
    };

    // struct key keytab[NKEYS];

    return 0;
}