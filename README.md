# HBCF
HitBox Collection Format

This is a super-tiny C++ module I'm working on to identify a collection of static physics objects from a string. This would be useful for a C++ game, methinks

## File Format Rules

### You can unclaimed symbols or whitespace freely.

This can be useful if it helps you group together related values visually (like sets of coordinates):
`R (10,10) , (3,3);`

The interpreter doesn't actually read them, so they are legal. You can even put whitespace in between digits, if you are a psychopath.
The only symbols you cannot add or remove harmlessly are `;`, `.` and `,`.


### End an entry with a `;` semicolon.

This is pretty simple. An object ends with a semicolon, then the next object starts immediately as you feed more values in.

## Usage

The `GetHitbox_Vector()` function possesses one argument, which should be a char array.
