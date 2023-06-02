<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
 <h1>my_bcmp Function</h1>
</head>
<body>

  <p>In order to complete this task, you need to implement the following function:</p>
  <pre>
    int my_bcmp(const void *b1, const void *b2, int len);
  </pre>
  <p>Parameters:</p>
  <ul>
    <li><code>b1</code>: Pointer to the first memory segment.</li>
    <li><code>b2</code>: Pointer to the second memory segment.</li>
    <li><code>len</code>: Number of bytes to compare.</li>
  </ul>
  <p>Function Purpose:</p>
  <p>To compare the <code>len</code> bytes, starting from the location pointed to by <code>b1</code>, to the <code>len</code> bytes, starting from the location pointed to by <code>b2</code>.</p>
  <p>Return Value: 0 if the two memory segments contain the same content, otherwise a non-zero value.</p>
  <h2>Notes:</h2>
  <ul>
    <li>Memory segments can partially or fully overlap.</li>
    <li>Memory segments of length 0 are always considered identical.</li>
    <li>The function cannot assume that memory segments end with the character '0\', and it must not modify the segments.</li>
  </ul>
  <h2>Program Usage</h2>
  <p>The main program should:</p>
  <ul>
    <li>Read input from the user, including the string, two indices into the string, and the value of <code>len</code>. The indices represent pointers to the memory segments.</li>
    <li>Call the <code>my_bcmp</code> function.</li>
    <li>Print the result returned by the function.</li>
  </ul>
  <p>It is important to perform proper input validation before calling the function. If any input errors occur, the program should stop and display a detailed error message.</p>
  <h2>Error Examples:</h2>
  <ul>
    <li>One of the indices or the value of <code>len</code> is not a positive integer.</li>
    <li>One of the memory segments goes beyond the string's boundaries (according to the given indices and <code>len</code> value).</li>
  </ul>
  <p>The input to the program should be read from stdin and can come from the keyboard or a file (using redirection when running the program).</p>

  <p>The program should display a user-friendly prompt message specifying what the user should enter. It should also print the input data before calling the function. This way, the input will be displayed even when coming from a file.</p>
</body>
</html>
