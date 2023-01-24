# ctohtml-highlighter
a syntax highlighter which creates a html code with C code syntax highlighted

## current stage
Pre Alpha Release

<pre style="font-size:0.8em">
Pre Alpha Release - not even started anything to make sense of it.
Alpha Release - some things are kinda working but don't really expect any output
Borderline Alpha Release - most of the things are pretty much working
Beta Release - uhmm.. works are not works depends on the mood
Normal Release - removed some wrong things so it kinda mostly works
Debug/Making Sense Release - pretty good done. removing/ improving/ fixing everything
Release Release - finally done. v1.0 will be released here
</pre>

## todo
1. highlight C code (duh)
2. parse the code
3. find keywords
4. find a effective way to read the c file
5. come up with colors for each section of the code
6. find a way to easily create the html code
7. support the libraries
8. support user defined variables and functions
9. use a parameterized system to accept parameters like libraries used or a imported module from another user defined c file or something similar
10. make it all look pretty and memory efficient and actually usable
11. dark mode and a light mode version of the output file

## Plan
1. use internal CSS for styling
2. use a div box for the entire block
3. use the idea behind infix to postfix expression conversion (stacks) for everything
4. somehow use a two layer stack to both maintain the order/position as well as the type of each token  

## uhmm
1. resizable stack to save every token and another stack of the same size to store the type of the token.
2. open file and read each line
3. function to check keywords
4. function to check operators
5. function to check for variables and find all previously defined variables
6. function to check for user defined functions and find all previously defined functions
7. function to check for library functions before declaring them as user variables
8. a way to check for error and mark them in red (if possible/ optional ig) <br>
. <br>
. <br>
. <br>
0. create a html file <br>
1. create a internal CSS for them all <br>
2. use data from 2nd stack to form first stack tokens <br>
3. light mode, dark mode(default) output  (if possible/ optional ig) <br>
4. parameterized program to show which libraries are used or to show the included header files so that their functions can be color coded. (if possible/ optional ig) <br>

## License

[GNU General Public License v2.0](https://choosealicense.com/licenses/gpl-2.0/)
