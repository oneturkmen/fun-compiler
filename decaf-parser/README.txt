# Printing format

Dear Professor,
As we discussed about the printing format and you approved that,
I print everything in-order as specified in the assignment.
However, it does so in terms of class Node, not symbol table.
Example:

```
global program
   class_C class
   class_B class

B class_decl
   method_decl_funky int <- int
   var_decl_g E
```

Basically, I dump symbol tables one by one. You can see how,
for instance, `constructor_decl_A A <- void` is printed,
and then its scope printed next (after the new line).
