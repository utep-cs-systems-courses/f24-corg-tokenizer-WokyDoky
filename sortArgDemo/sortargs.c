#include "bst.h"  
  

/*
Read chapter 6. 
*/ 
int main(int argc, char **argv)	/* prints arguments in order */
{
  printf("the program name is <%s>\n", *(argv+0));
  for (char **p = &argv[1]; *p; p++)
    bstInsert(&bstRoot, *p);
  bstPrint(bstRoot);
  bstClear(&bstRoot);
}
