# Cipher-Coder
This is a basic Substitution Cipher Program that takes in a 26-character argument, which will be used as the cipher.
It first checks whether or not the Cipher is valid, by running a check on whether there is any repeating characters, or whether or not it is not the right fit.
If the check is valid, it will begin converting the plaintext. Each character in the plaintext will get their numerical value from 0->25, and will be replaced by the character indexed at said value in the Cipher.
Afterwards, it will return the ciphertext.
