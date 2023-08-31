#include <chapter6.h>
#include <chapter5.h>

#define NKEYS   (sizeof (keytab)/sizeof(struct key))





/* count C keywords*/
struct key keytab[] = {
    {"/*", 0},
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"define", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"include", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"signed", 0},
    {"static", 0},
    {"sizeof", 0},
    {"short", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"unsigned", 0}
};  



char *vars[] = {"char","double", "float", "int","long", "short","void"};  


int main(int argc, char *argv[])
{

    exercise6_2_6_3();
    exercise6_5();
    exercise6_6();

    return 0;
}
