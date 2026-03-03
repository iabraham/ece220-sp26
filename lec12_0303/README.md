# README

The file `running.asm` in this folder shows the implementation of a small
recursive function in LC3, in great detail. 

```
int running_sum(int n){
    int fn;
    if (n==1)
    fn = 1;
    else
    fn = n + running_sum(n-1);
    return fn;
}

int main(void){
    int n = 4;
    int answer = running_sum(n);
}
```

## A summary of function call/return

There are a lot of steps involved in using the runtime stack. However, the
steps are very mechanical and straightforward if you follow the steps
precisely. Normally the code is created by a compiler. In the following pseudo-code 
involving LC3 commands are shown as `COMMANDS` and otherwise as *pseudocode*.

 1. caller pushes arguments right to left
 1. caller executes `JSR`
 1. callee makes space for return value (`ADD R6,R6,#-1`)
 1. callee pushes return address (*PUSH R7*)
 1. callee pushes old frame pointer (*PUSH R5*)
 1. callee resets frame pointer (`ADD R5, R6 #-1`) This makes the frame pointer
    point to the first local.
 1. callee allocates locals by decrementing stack pointer(`ADD R6, R6, #-numLocals`)
 1. callee does its work (includes saving return value `STR Rx,R5,#3`)
 1. callee removes locals by incrementing stack pointer (`ADD R6, R6, #numLocals` or `ADD R6, R5, #3`)
 1. callee restores old frame pointer (*POP R5*)
 1. callee pops return address (*POP R7*)
 1. callee executes `RET`
 1. caller pops return value
 1. caller removes parameters by incrementing stack pointer (`ADD R6, R6, #numParams`)
 1. caller continues its execution

Notice the symmetry of the steps. The actions taken in the beginning to build
the stack frame are done in the reverse order to remove the stack frame. 
 
 * See steps 7/9, 5/10, 4/11, 1/14. These are symmetric (done by same entity) 
 * Steps 2/12 and 3/13 on the other hand are assymetric (done by different entities).

 Further reading: https://www.cs.colostate.edu/~fsieker/misc/runtimeStack/runtimeStack.html
