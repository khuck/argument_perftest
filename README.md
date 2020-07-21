# argument_perftest
Test of the cost of passing lists of arguments to functions in C

This is a test to determine whether passing multiple stack (register)
variables is lower overhead than packaging up the varaibles into
a structure and passing the address of the structure.

To run the test, modify `main.c` and change the GHZ of the processor
on which you are running to estimate the number of cycles per invocation.

I haven't validated my math/stats, so it's fair to assume I might have
made a mistake or two.
