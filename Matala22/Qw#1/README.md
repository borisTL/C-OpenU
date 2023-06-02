<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
<h1>Calculator for Sets </h1>
</head>
<body>
  
  <p>This program is a computer program that reads commands from standard input, decodes, and executes them. The commands involve operations on sets.</p>
  <h2>Set Type</h2>
  <p>The program defines a set type using `typedef`, which holds a set of integers from the closed range [0...127]. The set type should be memory-efficient, using a bit for each element in the set.</p>
  <h2>Initialization</h2>
  <p>The program initializes six variables of type `set` with the following names: `SETA`, `SETB`, `SETC`, `SETD`, `SETE`, `SETF`. At the beginning of the program, each variable is initialized as an empty set.</p>
  <h2>Supported Commands</h2>
  <p>The program supports the following commands:</p>
  <ul>
    <li><code>read_set</code>: Reads a list of comma-separated values and adds them to the specified set. The end of the list is marked by a negative number (-1).</li>
    <li><code>print_set</code>: Prints the elements of the specified set in ascending order, with a maximum of 16 values per line. If the set is empty, it prints "empty is set The".</li>
    <li><code>union_set</code>: Performs a union operation between two sets and stores the result in a third set.</li>
    <li><code>intersect_set</code>: Performs an intersection operation between two sets and stores the result in a third set.</li>
    <li><code>sub_set</code>: Performs a subtraction operation between two sets and stores the result in a third set.</li>
    <li><code>set_symdiff</code>: Computes the symmetric difference between two sets and stores the result in a third set.</li>
    <li><code>stop</code>: Stops the program execution.</li>
  </ul>
  <h2>Input Format</h2>
  <p>The input consists of one command per line. Each command is written in the following format:</p>
  <p><code>&lt;command_name&gt; &lt;operand1&gt; &lt;operand2&gt; &lt;result&gt;</code></p>
  <p>The operands and result are the names of the set variables defined earlier. Multiple operands should be separated by commas.</p>
  <h2>Example Commands</h2>
  <pre>
    read_set SETA, 5, 6, 5, 76, 44, 23, 23, 98, 23, -1
    print_set SETA
    union_set SETC, SETD, SETD
    intersect_set SETA, SETF, SETA
    sub_set SETC, SETC, SETC
    set_symdiff SETF, SETA, SETA
    stop
  </pre>
</body>
</html>
