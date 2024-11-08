# PS5: DNA Alignment

## Contact
Name: Braden Maillet
Section: 11:00
Time to Complete: 5 hours

Partner: Not-Applicable

## Description
Explain what the project does
    This projects takes 2 strings and using the needleman-wunsch algorithm calculates
    how to best align the 2 strings and their best possible cost of alignment.

### Features
Explain how you did the actual alignment including the data structures used.
    I used a vector<vector<int>> to create a matrix like structure which held the
    data needed for the needleman-wunsch algorithm. The algorithm starts at the
    furthest bottom right corner of the matrix and works backwards to (0,0) by rows.
    It checks both gap cases and the match/mismatch case for the smallest summation.
    After creating the matrix the alignment function traces back through the matrix
    and creates a formatted alignment with cost of both strings.

### Testing
Describe what the unit tests you wrote check for and why you picked them.
    testcost1-4: check the costs of 2 string alignments
                more specifically test the optdistance function
                and therefore the matrix.
    testendgaps: check that the alignment function is putting gaps in
                 the right string.
    testmin3a-c: tests the min3 function for all 3 cases.
    testpenaltymis: tests the penalty function for a mismatch.
    testpenaltymatch: tests the penalty function for a match.
    testswap: tests to make sure that the output of 
             the alignment function doesn't swap the strings.
### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
    I didn't have trouble with much at all. The only worth mentioning is I was having some confusion with the autograder because
    my alignment function was using '_' instead of what was intended in the assignment '-'.

## Analysis

### Example
Do one additional test case by hand. It should be constructed in such a way that you know the correct  output before running your program on it, and it should be a "corner case" that helps check if your program handles all special situations correctly. 

Please list:
 - a copy of the test case input
 - the expected test case output
 - whether your program ran correctly on it or not
 - optionally, any other remarks

### Specs
Your Computer
Memory: 8GB ddr4 ram
Processors: AMD Ryzen 5 5500U 2.1 ghz

Partner's Computer
Memory: NA
Processors: NA

### Runs
Fill in the table with the results of running your code on both your and your partner's computers.

note: programs "killed" for ecoli50000 and ecoli100000

| data file     | distance | memory (mb) | time (seconds) | partner time |
|---------------|----------|-------------|----------------|--------------|
|ecoli2500.txt  |     118  |    24.17    | 0.391135       |              |
|ecoli5000.txt  |  160     |     95.95   |  1.64831       |              |
|ecoli10000.txt |    223   |  382.6      |  5.29889       |              |
|ecoli20000.txt |  3135    |  1492       |  20.1193       |              |
|ecoli50000.txt |          |             |                |              |
|ecoli100000.txt|          |             |                |              |

Here is an example from another computer for some of the files.

| data file    | distance | time (s) |
|--------------|----------|----------|
|ecoli2500.txt |      118 |    0.171 |
|ecoli5000.txt |      160 |    0.529 |
|ecoli7000.txt |      194 |    0.990 |
|ecoli10000.txt|      223 |    1.972 |
|ecoli20000.txt|     3135 |    7.730 |

### Time
Assume the two strings are the same length (M = N).  By applying the doubling method to the data points that you obtained, estimate the running time of youu program in seconds as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input your program can handle if it is limited to one day of computation.

Provide a brief justification/explanation of how you applied the doubling method, and if you data seems not to work, describe what went wrong and use the sample data instead.
 - a = 1/20000000
 - b = 2
 - largest N = 1,314,534 (rounded)

 I plotted the points within a graph and found that y = (1/20000000)x^2 I then used this to find y = 86400 seconds

### Memory
Assume the two strings are the same length (M = N).  Look at your code and determine how much memory it requires as a polynomial function of N, in the form a * N^b for some constants a and b.  Determine the largest input size your computer can handle if limited to 8GiB of RAM.
 - a = 1/270000
 - b = 2
 - largest N = 44721

  I plotted the points within a graph and found that y = (1/270000)x^2 I then used this to find y = 44721
  this value sqaured is eqaul to 8gb of integer values

### Valgrind
Run valgrind and list any errors you see.  Identify whether the memory usage reported by valgrind almost matches the calculations in the previous section.

--1748020:0: aspacem Valgrind: FATAL: VG_N_SEGMENTS is too low.
--1748020:0: aspacem   Increase it and rebuild.  Exiting now.

It looks like the space available overflows. The program actually still runs for whatever reason. I am not sure what the memory looks like because valgrind doesn't create a massif file when this happens.

## Pair Programming
If you worked with a partner, do you have any remarks on the pair programming method? E.g., how many times did you switch, what are the tradeoffs of driving vs. navigating, etc.?

## Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

