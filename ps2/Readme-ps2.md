# PS2: Pythagorean Tree

## Contact
Name: Braden Maillet
Section: Comp 4
Time to Complete: 20 hours


## Description
Explain what the project does.

    This project takes 2 integer inputs. The first being the size of a square and the second being iterations of Pythagoras tree.
It will then output a colorful pythagoras tree.

### Features
Describe what your major decisions were and why you did things that way.

    After hours of trial and error I ended up using a couple methods to solve the positional troubles with this project.
This project is not hard because of the recursion but more so the sfml library and non-intuitive transformations. At first I 
create a base sqaure . then I set the size for the next squares using a fairly simple trigonometric algorithm (ie: previous size * sin(45)). After this I set the origin to either the right bottom corner or the left bottom corner. This is so I can use the same
rotation every iteration for the recursive function(-45 and 45 for left and right respectively). Then I change the position
using the the transform class. I take the transform of the previous object at the start of every recursive call. I then find the 
global position of the corner(different corners for left and right) of the previous sqaure using transformpoint (a function which returns
a global point based on the local point given, so (0,0) is the top left corner of the sqaure). After this i change the rotation,
and make a recursive call to the function. This series of events happens for both left and right sqaures and the function as a
whole makes 2 recursive function calls. The function returns when the myDraw._reps is equal to zero. I also implemented some very basic color into the function using a switch statement

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

    I had an imense amount of trouble understanding the Origin and how it relates to position in the sfml library.
It took me a lot of trouble shooting to understand that it was best to change the origin and then change the position 
so one did not effect the other. It also took a long time for me to learn that I could use the transform class
to use a point local to the square and turn it into a global point(ie local to the renderwindow). Previous to learning
this I was trying to find a way to manipulate x and y values to a new location. I was not able to find
a simple and clean solution for this due to the constant changing of rotation and size(or really a viable solution at all).
I beleive mostly everything works, There may be slight issues with the size of the window relative to the tree, but only
with very large or small inputs.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

    I implemented a simple color system based on a switch case statement in the recursive function. It is very simple
and only includes 6 colors


## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

https://en.sfml-dev.org/forums/index.php?topic=17116.0 // helped me understand transfrom and how it could help with position