# PS7: Kronos Log Parsing

## Contact
Name: Braden Maillet
Section: 11:00
Time to Complete: 3 hours


## Description
Explain what the project does.
    This projects parses through a log file from a kronos device. It creates an output file that 
    describes the time it took said device to boot up. It also can detect if the device failed to
    boot.

### Features
Describe what your major decisions were and why you did things that way.
    The only major decisions in this project was the decision to use
    regex and the ptime class from Boost. The ptime class holds
    all necessary information for detecting the duration it took to
    boot the device. The regex library allowed for the retreival of
    data from the log file quickly and easily.

### Approach
Describe your overall approach to solving this problem.
    I simply iterated through the entire log file using a while loop
    If i detected that withing a line of the log file there was the
    start regex than I recorded the time and line number and began 
    searching for the end regex. If the end regex was found then a 
    log of that boot was output to a file. In the case that I detected another 
    start regex than that indicated the device failed to boot and a special 
    log was output to the file.

### Regex
What regular expressions did you use?  Explain what each one does.
    I used a 2 regular expressions that contained the strings I was looking
    for that indicated a start or end of boot. They also specified with .* at the 
    beginning and end that anything could come before or after these strings.
### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
    I didn't run into any trouble at all. I did learn a bit about regex's and the boost test library.

### Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
