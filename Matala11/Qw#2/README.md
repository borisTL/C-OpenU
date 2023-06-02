<!DOCTYPE html>
<html>
<head>
 <h1>README</h1>
</head>
<body>

  <p>
    This is a readme file for the <code>shorten_string</code> program, which is designed to shorten a given string according to specific rules.
  </p>

  <h2>Functionality</h2>
  <p>
    The <code>shorten_string</code> function takes a string as a parameter and shortens it based on the following rules:
  </p>

  <ol>
    <li>Search for consecutive substrings within the string that consist of uppercase and lowercase English alphabet letters only.</li>
    <li>The length of each substring must be at least 3 characters.</li>
    <li>Each substring will be shortened to three characters: the first letter, a hyphen, and the last letter.</li>
  </ol>

  <p>
    For example, given the string: "dabcefLMNOpQrstuv567zyx"
    <br>
    There are three consecutive substrings that meet the criteria:
    <br>
    - "dabcef" will be shortened to "da-cef"
    <br>
    - "LMNOpQ" will be shortened to "LMN-pQ"
    <br>
    - "rstuv567zyx" will be shortened to "rs-xx"
    <br>
    The resulting shortened string will be: "da-cef LMN-pQ rs-xx"
  </p>

  <h2>Usage</h2>
  <p>
    To use the program, you need to call the <code>shorten_string</code> function with a string parameter. The function will modify the string in-place and return the shortened version.
  </p>

  <p>
    Additionally, you should create a main program that prompts the user for input, calls the <code>shorten_string</code> function, and prints the shortened string in a user-friendly manner.
  </p>

  <p>
    The maximum length of the input string is assumed to be 80 characters.
  </p>

  <p>
    The input is read from the standard input (stdin), which can be entered from the keyboard or redirected from a file using input redirection during program execution. You can create multiple input files for convenient debugging of the program.
  </p>

  <p>
    The program should display a friendly request message for input. It should also print the shortened string in a presentable manner.
  </p>
</body>
</html>
