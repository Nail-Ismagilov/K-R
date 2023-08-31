
#define NSYM    100

/* A union is a variable that may hold (at different times) objects 
 * of different types and sizes, with the compiler keeping track of 
 * size and alignment requirements. Unions provide a way to manipulate
 * different kinds of data in a single area of storage, without adding
 * any machine-dependent information in the program. */

/* The syntax is based on structure */
union u_tag{
    int iVal;
    float fVal;
    char *sVal;
}u;
/* the variable u will be large enough to hold the largest of three types; 
 * the specific size is implementation dependent. Syntatically, members of 
 * a union are accesssed  as:
 *       union-name.member
 *  or
 *       union-name->member
 *  just as for structures. */

/* Unions may appear within structures and arrays, and vice versa. The notation for
 * accessinf a member of a union in a structure(or vice versa) is identical to that 
 * for nested structures. For example in the structure array defined by */

struc{
    char *name;
    int flags;
    int utype;
    union{
        int iVal;
        float fVal;
        char * sval;
    } u;
} symtab[NSYM];

void example()
{
    int i;
    for (i = 0; i < NSYM; i++)
        symtab[i].u.iVal;
        *symtab[i].u.sVal;
        symtab[i].u.sVal[0];
}

/* The same operations are permitted on unions as on structures: 
 * assignment to or copying as a unit, taking the address, and 
 * accsessing a member. A union may only be initialized with a 
 * value of type of its first member.*/
