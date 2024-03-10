# Advanced Binary Scanner

Discover and stop the hidden "crypty" virus with the Advanced Binary Scanner. 

As an input, the program gets 2 arguments:
1. **Root Directory Path:** The starting point of the search.
2. **Signature File Name:** A file containing the signature.

# Usage
#### $ bin/find_sig /usr/bin crypty.sig
#### Scanning initiated...
#### [Console] File /usr/bin/ls is infected!
#### [Console] File /usr/bin/sys/prog1 is infected!

# Build the project
make
# Clean generated files
make clean

# Test the project
#### $ make
#### $ bin/find_sig /home test/crypty.sig
#### ![running_example](https://github.com/IlayCh/SigScanner/assets/90407670/e6fb5040-257f-492d-9ac3-a5fb70c09c8f)

