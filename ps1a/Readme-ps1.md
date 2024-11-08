# PS1: LFSR / PhotoMagic

## Contact
Name: Braden Maillet

Section: Comp 2040 204

Time to Complete: 5 hours


## Description
Explain what the project does.

	This project mimicks the function of a linear feedback shift register. It is a class that is initialized with a seed(16 bits). This seed
	can then be shifted to create a new string of bits based on the "taps" of the previous string. In this case the taps are at bit locations
	15, 13, 12, 10. These taps are Xor'd and if they return true the new bit pushed on the the left side of the binary string with be a 1.

### Features
Describe the representation you used and why you did things that way.

	 I decided to base by FibLFSR class around a integer because I was familiar with integer bit shifting operations. Additionally I thought it
	 was likely more efficient than using say the bitwise class because I would 1, only be allocating space for a single integer and 2, not have
	 to worry about dynamic allocation. I also included variable _size aswell as _seed which held the bit size of the memory represented
	 as abinary string as well as the original seed initialized to the class.

### Issues
What doesn't work.  Be honest.  You might be penalized if you claim something works and it doesn't.

     	 I am not aware of anything that doesn't work. I would like to note that it seems there is an error in the assignment pdf
	 within the section "Extracting multiple bits".
     	     
### Tests
Describe what is being tested in your Boost unit tests.
	 TestCase1: testClassSize
	 	 tests the variable _size after initialization.
	 TestCase2: teststepzero
	 	 test an edge case on the function step to make sure the correct shift is being made
	 TestCase3: teststepone
		 tests another edge case on the function step to make sure the correct shift is being made
	 Testcase4: testseednochange
	         ensures that the variable _seed does not get modified when generate/step is called.
	 TestCase5: testbitostring
	 	 ensures that the function testbitostring works properly. the Binary to string function
		 that I developed is very important for the execution of other functions aswell
		 as the operator overload <<.
### Extra Credit
Anything special you did. This is required to earn bonus points.
## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
    - Use of macro LOG_DEBUG can be accredited to Dr. Weis as seen in a computing 1 lecture.
