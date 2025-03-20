# HBCF
HitBox Collection Format

This is a super-tiny C++ module I'm working on to identify a collection of static physics objects from a string. This would be useful for a C++ game, methinks

## File Format Rules

### Whitespace is only okay outside an object's data.

Do not do this:
`T[ 0 , 0 , 3 , 3]`

This is okay:
`T[ 0, 0, 3, 3]`

### You can use parentheses...  

if it helps you group together related values visually (like sets of coordinates):
`R[ (10,10) , (3,3) ]`

The interpreter doesn't actually read them, so they are legal where any useless character would be.

### Contain object contents in brackets.

The letter at the beginning of an object is the first value that will be exported, but every other value must be behind brackets proceeding it
