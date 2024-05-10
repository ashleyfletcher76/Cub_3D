Key points

* We use a manually implemented flood fill. Avoiding a recursive flood fill that could potentially lead to stack overflow. We check several conditon when moving around the map and if they meet these conditions, we add the x and y coordinates onto the malloc'd stack.

* We increment the stack int eh move_point x and y functions upon these check and then decrement in the main so we can view if these coordinates have violated our boundary conditions.
