/*
 * The file contains examples and exercises from K&R 
 * "The C Proggramming languages" book. Chapter 6.2
 *
 * */

#include <stdio.h>

#define XMAX    320
#define YMAX    200     

#define MIN(A,B)    ((A) < (B) ? (A) : (B))     
#define MAX(A,B)    ((A) > (B) ? (A) : (B))

struct point makepoint(int, int);
struct point addppoint(struct point, struct point);
struct rect screen;
struct point middle;

struct point
{
    int x;
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};

/* makepoint: make a point from x andy components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
};

int main()
{
    
    /* makepoint can now be used to initialize any structure dynamically
    or to provide structure arguments to a function. */

    screen.pt1 = makepoint (0,0);
    screen.pt2 = makepoint (XMAX, YMAX);
    middle = makepoint ((screen.pt1.x + screen.pt2.x)/2,
                    (screen.pt1.y + screen.pt2.y)/2);
    
    /*using pointer structure */
    struct point origin, *pp;

    pp = &origin;
    printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);

    return 0;
}



/* the next step is to do arithmetic on points */
/* addpoint: add two points */
struct point addppoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;   
}

/* The function printrect test whether a point is inside a rectangle,
    where we have adopted the convention that a rectangle includes left 
    and bottom sides buit not its top and right sides   */

/* printrect: return 1 if p in r, 0 if not */
/* it assumes that the rectangöe is represented in a standard form
    where the pt1coordinates are less than the pt2 coordinates. */
int printrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x <= r.pt2.x &&
           p.y >= r.pt1.y && p.y <= r.pt2.y;
}

/* The following function returns a rectangle guaranteed to be in cannonical form.
    It uses MAX and MIN macrofunctions.*/

/* canorect: canonicalize coordinates of rectangle */
struct rect canonrect (struct rect r)
{
    struct rect temp;
    temp.pt1.x = MIN(r.pt1.x, r.pt2.x);
    temp.pt1.y = MIN(r.pt1.y, r.pt2.y);

    temp.pt2.x = MAX(r.pt1.x, r.pt2.x);
    temp.pt2.y = MAX(r.pt1.y, r.pt2.y);

    return temp;
}

/* If a large structure is to be passed to a function, it is generally more efficient
    to pass a pointer rathe than to copy the whole structure.  Structure pinters are just 
    like pointers to ordinary variables.*/

    struct point *pp;
