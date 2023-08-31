/* When a storage at a premium it is necessary to pack
 * several objects into a single machine word; one common 
 * use is a set of single-bit flags in applications like 
 * compiler symbol tables. 
 *  Imagine a fragment of a compiler that manipulates a 
 *  symbol table. Each identifier in a program has certain
 *  information associated wit it, for example, whether or
 *  not it is a keyword, external/static etc. The most compact
 *  way to encode such information is a set of one-bit flags
 *  in single char or int. 
 *      The usual way is done is to define a set of masks
 *  corresponding to the relevant bit position. */
#define KEYWORD  01
#define EXTERNAL 02
#define STATIC   04

/* or enum{ KEYWORD = 01, EXTERNAL = 02, STATIC = 04};
 * The numbers must be power of two. Then accessing the bits become a matter of "bit-fiddling"
 * with the shifting, masking and complementing operators. */

void example()
{
    int flags = 0;

    /* certain idioms appear frequantley: */
    flags |= EXTERNAL | STATIC;
    /* turns on EXTERNAL and STATIC bits in flags, while:*/
    flags &= ~(EXTERNAL | STATIC);
    /* turns them off, and*/
    if ((flags & (EXTERNAL | STATIC)) == 0)
    /* is true if both bits are off*/
    {
        int j = 0;
    }
    
}

struct{
        unsigned int is_keyword : 1;
        unsigned int is_extern  : 1;
        unsigned int is_static  :1;
} flags;

/* this defines a variable called flags that contains three
 * 1-bit fields. The number following the colon represents the field
 * width in bits. The fields are declared unsigned int to ensure that 
 * they are unsigned  quantities. */