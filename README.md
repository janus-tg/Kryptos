# Kryptos

This project was named after the famous sculpture containing unencrypted texts located outside the CIA HQ at Langley. This is a C program that utilizes dynamic memory allocation and sorting for string manipulation to encrypt or decrypt user entered text in 10 of the most famous ciphers used throughout human history. 


<img src="image.png" width="750">


## Running the program

1. Install any IDE with a suitable C compiler.
2. Create a new project, copy the ```Source.c``` code and paste it in a ```.c``` file.
3. Remove the first line: ```#define _CRT_SECURE_NO_WARNINGS``` from the code
4. Run the program.

**Note:** Only users running this program on Visual Studio on the MSVC compiler *must* ignore step 3 above.

**OR**

For OS X and Linux

1. Download the ```Source.c``` file and remove the first line: ```#define _CRT_SECURE_NO_WARNINGS``` from the code.
2. Then, open the folder containing the ```Source.c``` file in the terminal.
3. Type ```clang Source.c -o Source``` and press enter in the terminal. (If compiler is gcc, then replace clang with gcc)
4. Finally, type ```./Source``` and press enter to run the executable. 

## List of ciphers available

Click to read more about these ciphers!

1. [Atbash](https://en.wikipedia.org/wiki/Atbash)
2. [Scytale](https://en.wikipedia.org/wiki/Scytale)
3. [Caesar shift](https://en.wikipedia.org/wiki/Caesar_cipher)
4. [Affine](https://en.wikipedia.org/wiki/Affine_cipher)
5. [Vigenere](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
6. [Bacon](https://en.wikipedia.org/wiki/Bacon%27s_cipher)
7. [Playfair](https://en.wikipedia.org/wiki/Playfair_cipher)
8. [Bifid](https://en.wikipedia.org/wiki/Bifid_cipher)
9. [ADFGX](https://en.wikipedia.org/wiki/ADFGVX_cipher)
10. [Hill](https://en.wikipedia.org/wiki/Hill_cipher#:~:text=In%20classical%20cryptography%2C%20the%20Hill,than%20three%20symbols%20at%20once.)

## Contributing

Pull requests are welcome for adding more ciphers or fixing exisiting issues. 

## License

[MIT](https://github.com/ghosetuhin/Cryptography/blob/master/LICENSE)
