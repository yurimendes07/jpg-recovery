# jpg-recovery
Made as a CS50 challenge, but it was so cool and harsh to do that I would like to put in my portfolio.
To run it, is easier creating a codespace with it.
Or if you are using linux, you could do the same, windows user are just sad rn.
In command bar type:
make recover
Then type:
./recover <filename>

As Elon Musk said: "If the person really put energy in something he create, he could describe how he create in detais."
not in that words, but I don't remember, so whatever.
Down there will describe how I've done this.
By first I open the file with stdio.h, so we need to verify if file is ok, 
so we test if it is equals null, if not we return 1, a code to say that something goes wrong,
as said in challenge, the jpg  has "block_size" of bytes, what makes easier to read in a loop,
we get all bytes in loop and put in a variable, and verify if the first bytes are equal to
default jpg header, which is 0xff 0xd8 0xff, inside this if, we verify if there is already a
jpg being written, this is an optimization, if we put this later the code could get bigger,
as I already worked with python was easy to make filename, that changes from 000 as a place holder
and go 001, 002, and there goes, sprintf makes that, %03d is to say to C that we want 3 digits in string
like %.1 that says to C we want 1 decimal, 1.0 for example.
Leaving this if, if there is a file to be written, we write on it.
So we close the file. 
Thing like free and malloc are hard to explain, so if you really read 'till here, 
watch a youtube video that will describe better and quickier.
In the end are printed the number of files to user know how many files were recovered.

