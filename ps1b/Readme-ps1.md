# PS1: LFSR / PhotoMagic

## Contact
Name: Braden Maillet

Sections: Computing 4 204

Time to Complete: 6 hours

##Level of Functionality

To my knowledge the program is fully functional.
Although I did run into a linting issue that I
think I should not lose credit for:
PhotoMagic.hpp:10:  Is this a non-const reference? If so, make const or use a pointer: sf::Image& image  [runtime/references] [2]
The linting error wants me to change the given parameter for the function we are supposed to create.


## Description

This projects takes 3 string arguements for input. The first being
a .jpg photo file, the second a photo output file and the third a bit string seed.
Once the program is executed the input photo is encrypted using the seedand output as
a jumble of random pixels. Although if you use the same seed on the jumble of pixels
it will decrypt back into the original image. Commands to encrypt and decrypt are as follow.

encrypt: ./PhotoMagic cat.jpg cat-out.bmp 1011011000110110
decrypt: ./PhotoMagic cat-out.bmp cat-out.bmp 1011011000110110

*these commands should work with and seed aslong as it is the same for both.*
