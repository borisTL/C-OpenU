<!DOCTYPE html>
<html>
<head>
 <h1>Definition: Permutation</h1>
</head>
<body>
 
  <p>A permutation of a string is a string obtained by some rearrangement of the characters in the original string.</p>

  <p>Your program should accept two arguments in the command line: the name of an input file and a string of characters.</p>

  <p>The program should scan the contents of the file and print to the standard output all the permutations found in the file.</p>

  <p>The permutations should be printed in the order of their occurrence in the file. Each permutation should be printed on a new line. Multiple occurrences of the same permutation may exist, and all of them should be printed.</p>

  <p>For example, if the command line looks like this: and the content of the input file "in.data" is:</p>

  <pre>
    I am a chair
    You ar e an ar ich and not a CHAIR
    We ar e hair cs and not gariches
    Goodbye
  </pre>

  <p>The output of the program should be:</p>

  <pre>
    chair
    arich
    hairc
    ar ich
  </pre>

  <p>The program should print an appropriate error message to the standard error file and exit under the following cases: the number of arguments in the command line is incorrect, there is a problem opening the file, or the file is empty.</p>

  <p>In case the program has scanned the entire contents of the file but did not find any permutations, it should print an appropriate message to the standard output file and terminate.</p>

  

</body>
</html>
