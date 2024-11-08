# PS6: RandWriter

## Contact
Name: Braden Maillet
Section: COMP 4 11am
Time to Complete: 10 hours


## Description
Explain what the project does.
    This projects takes and analyzes a large amount of text. Using this text it creates markovs chains based on the
    afforementioned text. It then can output a given amount of text that is modeled after the statistical analysis
    of the text that was input.
### Features
Describe what your major decisions were and why you did things that way.
    I decided to create a kgram class and use that within a map. This way I could hold another map and other necessary
    information within each kgram. Specifically kgram + 1.

### Testing
What tests did you write?  What exceptions did you use?  Does your code pass the tests?
    testlength:  tests for the correct length of the generate function.
    testexceptionfreq:  tests that freq(string) throws an exception for a string of the wrong order.
    testnoexceptionfreq: tests that freq(string) doesnt throw an exception for a string of the right order.
    testexceptionfreqc: tests that freq(string, char) throws an exception for a string of the wrong order.
    testnoexceptionfreqc1: tests that freq(string, char) does not throw an exception for a string of the right order.
    testnoexceptionfreqc2: tests that freq(string, char) does not throws an exception for a string that wraps around.
    testordk:  tests the orderk function for correct order.
    testkrandexcept1:  tests that krand throws an exception for kgram of the wrong order.
    testkrandexcept2:  tests that krand throws an exception for a kgram that doesnt exist.
    testkrandnoexcept:  tests that krand doesn't throw an exception
    teststart1:  tests that the generate function has correct start

### Lambda
What does your lambda expression do?  What function did you pass it to?
    
### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
    I had a slight amount of trouble with creating an alphabet based on the given input text. But once I discovered the property of unordered_set, it became easy. The property being that every element in an unordered set is unique.
### Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
