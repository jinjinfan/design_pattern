#Visitor
A pattern where a component(visitor) is allowed to traverse the entire inheritance hierarchy. Implemented by progating a single visit() function through the entire hierarchy.

#Dispatch
which function to call?
Single dispatch: depends on name of request and type of receiver.
Double dispatch: depends on name of request and type of two receivers(type of visitor, type of element being visited).
