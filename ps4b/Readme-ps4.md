# PS4: N-Body Simulation

## Contact
Name: Braden Maillet
Section: Comp 4
Time to Complete: 10 hours


## Description
Explain what the project does.

    This project simply sets up the Universe and CelestialBodys into a window on the screen. It takes input from
data collected within a file.

### Features
Describe what your major decisions were and why you did things that way.

    The biggest decision to be made with this project was the way in which the celestialBodys were
stored within the Universe class. I decided to create a vector of smart pointers to celestial bodys.
This seemed like the simplest way to set things up and the concensus from my group discussion in
class. The second biggest decision withing this project was the way in which the celestial bodys
were fit into the window. I decided to use the setView function. With some simple math I was able to
slice off any blank space from the furthest object to the edge of the screen. This allowed for a
nice fitment of the celestialBodys.

### Memory
Describe how you managed the lifetimes of your objects, including if you used smart pointers.

    I manage my Celestial bodys within my universe class. More specifically they are held as
smart pointers within a vector.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

    I had a little trouble with the viewpoint stuff but not much else.

### Extra Credit
Anything special you did.  This is required to earn bonus points.
If you created your own universe file.  Describe it here and explain why it is interesting.

I created my own file call nbody-full/myfile.txt. It contains 2 earths and one sun. The sun is 
in the center and the 2 earths revolve around the sun and pull close enough to the sun to create
a cool movement around the sun.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

NA
