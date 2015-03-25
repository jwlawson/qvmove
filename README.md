# qvmove

`qvmove` is a program to check the number of moves required to transform any
minimal mutation-infinite quiver to one of the class representatives.

`qvmovecl` computes the whole move-class of a given minimal mutation-infinite
quiver.


### Usage of qvmove

```
qvmove [-i input] [-o output]
```
* `-i` Specify a file to read matrices in. If not specified then stdin is used.
* `-o` Specify a file to write the output to. If not specified then stdout is
	used.

##### Expected input

The program expects the input to be matrices formatted as in the [libqv]
library. Each matrix should be on a new line.

##### Output

The output for a given input matrix is of the form:
```
x(y) { input_matrix }
```
where `x` is the number of moves and `y` is the number of sink-source mutations
required to transform `input_matrix` to one of the class representatives.

### Usage of qvmovecl

```
qvmovecl -m matrix
```
* `-m` Specifies the matrix to use to compute the class

##### Output

Outputs all matrices in the move-class of the input matrix. Each matrix is
formatted as in the [libqv] library and is on its own line.

### Build

Run `make` to compile `qvmove` and `qvmovecl`.

##### Dependencies

`qvmove` requires the following libraries and their headers to be
installed and accessible by the compiler:

 * [libqv][libqv site]

The Makefile can be modified to include the install locations of these
libraries, by changing the `INCLUDES` and `LFLAGS` variables.

### License

```
   Copyright 2014-2015 John Lawson

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
```

[libqv]: http://github.com/jwlawson/qv

