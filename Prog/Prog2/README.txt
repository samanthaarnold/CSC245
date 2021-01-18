Converting Infix Expression to Postfix in Client File-

My plan to convert an infix expression to postfix is to use the algorithm we discussed in class
when we working on converting these expressions on paper. The algorithm is as follows-
    1) Push ( onto the stack.
    2) Output all operands onto a string.
    3) When you get to an operator, check to see if there is any operators on top of the 
    stack. If so, pop all operands of higher or equal value and output them to the string. 
    Create a method, say operatorPrec, that will check the order of operations. Then, 
    continue to push operators on. 
    4) If you see ), pop all stack symbols until you find a (. Then pop (.
    5) Once you reach the end of the input, pop all remaining stack symbols. 
Once we have a string converted to postfix, then we can use the BuildTreePostix method to build 
the binary expression tree and use preorder, inorder, and postorder traversal to print the tree. 

Description of Methods in Implementation File-
    -insertOperand(): First starts by delcaring a new pointer to a binary node. Then uses this 
    pointer to reference the specification file and set a char that is sent in as a parameter 
    equal to the address of the operand. Then, the left and right branches are declared as NULL,
    and the pointer is pushed onto the stack of binary nodes from the specification file. 
    
    -insertPostfixOperator(): First starts by delcaring a new pointer to a binary node. Then uses this 
    pointer to reference the specification file and set a char that is sent in as a parameter 
    equal to the address of the operator. Then, the right branch of the binary node being accessed is set
    to the top of the stack of binary nodes. Then, it is popped from the stack. Then the left branch of 
    the binary node is set to the top of the stack of binary nodes and popped as well. Then, the pointer 
    is pushed onto the stack and the root becomes the new top of the stack. 
    
    -insertPrefixOperator(): First starts by delcaring a new pointer to a binary node. Then uses this 
    pointer to reference the specification file and set a char that is sent in as a parameter 
    equal to the address of the operator. Then, the left branch of the binary node being accessed is set
    to the top of the stack of binary nodes. Then, it is popped from the stack. Then the right branch of 
    the binary node is set to the top of the stack of binary nodes and popped as well. Then, the pointer 
    is pushed onto the stack and the root becomes the new top of the stack. 