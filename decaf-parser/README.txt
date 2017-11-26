# Printing format

Dear Professor,
I tried to print everything in-order as specified in the assignment.
It actually does so, but in terms of class Node, not symbol table.
However, now I print as the following example:

```
global program
   class_C class
   class_B class
   class_E class
   class_A class

A class_decl
   constructor_decl_A A <- void
   var_decl_b B

A constructor_decl

B class_decl
   method_decl_funky int <- int
   var_decl_g E
```

Basically, I dump symbol tables one by one. You can see how,
for instance, `constructor_decl_A A <- void` is printed,
and then its scope printed next (after the new line).

Please let me know if that satisfies the requirements, though specified
to do the other way. If not, I will redo this.

# Constructor as a name space
As `constructor_decl` has its own block, I assume that it also has its own
name space. I.e. you can declare variables in it, that are only visible by
class scope and not by neighbor methods.

# Implementation specifics
So, as you approved, I decided to do type checking in 2 stages.
In the first stage, I create symbol tables and fill them in as necessary.
In the second stage, I check if the types exist, variables exist, if types
match, if all arguments are provided in order, etc. 
