# ctohtml-highlighter
a syntax highlighter which creates a html code with C code syntax highlighted


## todo
1. highlight C code (duh)
2. parse the code
3. find keywords
4. find a effective way to read the c file
5. come up with colors for each section of the code
6. find a way to easily create the html code
7. support the libraries
8. support user defined variables and functions
9. use a parameterized system to accept parameters like libraries used or a imported module from another user defined c file or something similar.
10. make it all look pretty and memory efficient and actually usable.
11. dark mode and a light mode version of the output file.

## Plan
1. use internal CSS for styling.
2. use a div box for the entire block
3. use the idea behind infix to postfix expression conversion (stacks) for everything
4. somehow use a two layer stack to both maintain the order/position as well as the type of each token  

## License

[GNU General Public License v2.0](https://choosealicense.com/licenses/gpl-2.0/)
