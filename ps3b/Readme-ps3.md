# PS3b: Sokoban

## Contact
Name: Braden Maillet
Section: Comp 4
Time to Complete: 10 hours


## Description
Explain what the project does.

This project takes input from a text file and creates an environment from that file. The environment is a 
room that contains a player, boxes, walles and storage areas. The goal of the game is you(the player)
to push boxes into the given storage areas. To win the game you either have to fill all storage areas with boxes
or put all the boxes in storage areas. The game can reset using the keystroke R and movement of the player 
is controlled using keystrokes WASD.

### Features
Describe what your major decisions were and why you did things that way.

I decided to use a vector<vector<char>> to represent the game grid or arena. I thought this was best as I wouldn't
have to worry about dynamically allocating memory. It also allows me to access elements easily using [][].
I also decided to hold all of the needed images within the sokoban class as textures. They are loaded once
when the class is default constrcted and can be used for sprites within other functions.

### Memory
Describe how you decided to store the level data including whether you used smart pointers.

I stored the level data within a vector<vector<char>> as previously stated and I did not make the decision to use smart pointers.

### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.

I used the algorithm "count_if" withing the iswon() function designed in my sokoban class. Within this 
count_if function I used a lambda expression that returned true if given the correct character was found.
Overall the count_if function coupled with the lambda expression helped to find the count of certain
objects within the original and current environment. Using this data I was able to determine 
if the game had been won or not.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

There was nothing I had a lot of trouble with. I took a little bit of troubleshooting to figure out the file io, but
that was mostly due to errors with calling from files(image.png vs directory/image.png).

### Extra Credit
Anything special you did.  This is required to earn bonus points.

N/A

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

Kenney Sokoban Pack (CC0): https://kenney.nl/assets/sokoban

Kode Mono(text) designed by Isa Ozler https://fonts.google.com/specimen/Kode+Mono/about