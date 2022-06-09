## This program Decodes an Encrypted text(a Morse Code) into readable text.

import re
def to_letter_text(morse_code):
   
    code = {
        'a':'.-', 'b':'-...', 'c':'-.-.', 'd':'-..', 'e':'.', 'f':'..-.', 
        'g':'--.', 'h':'....', 'i':'..', 'j':'.---', 'k':'-.-', 'l':'.-..', 'm':'--', 
        'n':'-.', 'o':'---', 'p':'.--.', 'q':'--.-', 'r':'.-.', 's':'...', 't':'-',
        'u':'..-', 'v':'...-', 'w':'.--', 'x':'-..-', 'y':'-.--', 'z':'--..',
        '0':'-----', '1':'.----', '2':'..---', '3':'...--', '4':'....-',
        '5':'.....', '6':'-....', '7':'--...', '8':'---..', '9':'----.', ' ':'/'
    }
    decode = {value: key for key,value in code.items()}

    if re.match('(\s|-|\.)+', morse_code):
        return ''.join(decode[i] for i in morse_code.split())
   
morse_code = input("Enter morse code to decode: ")
print(to_letter_text(morse_code))
