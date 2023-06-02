<!DOCTYPE html>
<html>
<head>
    <h1> Assembler</h1>
</head>
<body>

  
  <p>This project is based on the <strong>two-pass assembler</strong> model. Please note that the computer model used in this project and the associated assembly language are <strong>imaginary</strong>.</p>

  <h2>Getting Started</h2>
  
  <p>The project was coded and compiled using Ubuntu but should run on all Linux versions.</p>

  <h3>Usage</h3>
  
  <p>To compile the project, use the provided makefile with the following command:</p>

  <pre>> make</pre>

  <p>After preparing assembly files with the <code>.as</code> extension, open the terminal and pass the file names (without the extensions) as arguments, as shown below:</p>

  <pre>> assembler x y hello</pre>

  <p>The assembler will generate output files with the same filenames and the following extensions:</p>

  <ul>
    <li><code>.ob</code> - Object file</li>
    <li><code>.ent</code> - Entries file</li>
    <li><code>.ext</code> - Externals file</li>
  </ul>

  <p>An example of input and output files can be found under the 'tests' folder.</p>

  <h2>Hardware</h2>

  <ul>
    <li>CPU</li>
    <li>RAM (including a stack), with the size of 256 <em>words</em></li>
    <li>A <em>word</em>'s size in memory is <strong>14 bits</strong></li>
    <li>Uses signed <em>2's complement</em> arithmetic for integers (with no support for real numbers)</li>
  </ul>

  <h3>Registers</h3>

  <p>The CPU has 9 registers: 8 general registers (named r0, r1, r2, ..., r7) and a register called <em>PSW</em> (program status word). The size of each register is a <em>word</em> (14 bits).</p>

  <h2>Instruction Structure</h2>

  <p>Every software <em>instruction</em> is encoded into a few <em>words</em> in memory (maximum is 5 words). The first word has the following structure:</p>

<table>
  <tr>
    <th>13-12</th>
    <th>11-10</th>
    <th>9-6</th>
    <th>5-4</th>
    <th>3-2</th>
    <th>0-1</th>
  </tr>
  <tr>
    <td>Parametr1</td>
    <td>Parametr2</td>
    <td>Opcode</td>
    <td>Source operand addressing method</td>
    <td>Destination operand addressing method</td>
    <td>ARE</td>
  </tr>
</table>




  <h2>Commands</h2>

  <p>The commands allowed in bits 6-9 are:</p>

  <table>
    <tr>
      <th>Opcode (decimal)</th>
      <th>Command Name</th>
    </tr>
    <tr>
      <td>0</td>
      <td>mov</td>
    </tr>
    <tr>
      <td>1</td>
      <td>cmp</td>
    </tr>
    <tr>
      <td>2</td>
      <td>add</td>
    </tr>
    <tr>
      <td>3</td>
      <td>sub</td>
    </tr>
    <tr>
      <td>4</td>
      <td>not</td>
    </tr>
    <tr>
      <td>5</td>
      <td>clr</td>
    </tr>
    <tr>
      <td>6</td>
      <td>lea</td>
    </tr>
    <tr>
      <td>7</td>
      <td>inc</td>
    </tr>
    <tr>
      <td>8</td>
      <td>dec</td>
    </tr>
    <tr>
      <td>9</td>
      <td>jmp</td>
    </tr>
    <tr>
      <td>10</td>
      <td>bne</td>
    </tr>
    <tr>
      <td>11</td>
      <td>red</td>
    </tr>
    <tr>
      <td>12</td>
      <td>prn</td>
    </tr>
    <tr>
      <td>13</td>
      <td>jsr</td>
    </tr>
    <tr>
      <td>14</td>
      <td>rts</td>
    </tr>
    <tr>
      <td>15</td>
      <td>stop</td>
    </tr>
  </table>

  <h2>Macro</h2>

  <p>Macros are pieces of code that include statements. In the program, you can define a macro and use it in different places. Using the macro from a certain place in the program will cause the macro to be allocated to that place.</p>

  <p>Defining a macro is done as follows (in the example, the name of the macro is m1):</p>

  <pre>
  mcr m1 inc r2
   mov A,r1
  endmcr

  m1

  after
  mov A,r1
  </pre>

  <h2>Directives</h2>

  <p>A <strong>directive</strong> line has the following structure:</p>

  <ol>
    <li>An <strong>optional</strong> preceding <em>label</em>. e.g., <code>PLACE1: </code>.</li>
    <li>A <em>directive</em>: <code>.data</code>, <code>.string</code>, <code>.struct</code>, <code>.entry</code>, or <code>.extern</code>.</li>
    <li>Operands according to the type of the <em>directive</em>.</li>
  </ol>

  <h3><code>.data</code> Directive</h3>

  <p>This directive allocates memory cells for storing <strong>integer</strong> values. The allocated memory cells are initialized with the values given in the operands. The format is as follows:</p>

  <pre>
  label1: .data [initialValue] [, initialValue]...
  </pre>

  <h3><code>.string</code> Directive</h3>

  <p>This directive allocates memory cells for storing <strong>character</strong> values. The allocated memory cells are initialized with the ASCII codes of the characters given in the operands. The format is as follows:</p>

  <pre>
  label1: .string [initialString]
  </pre>

  <h3><code>.struct</code> Directive</h3>

  <p>This directive allocates memory cells for storing <strong>structs</strong>. The allocated memory cells are initialized with the values given in the operands. The format is as follows:</p>

  <pre>
  label1: .struct [initialValue] [, initialValue]...
  </pre>

  <h3><code>.entry</code> Directive</h3>

  <p>This directive defines a <em>label</em> as <strong>external</strong> and is used to enter an external label defined in another file. The format is as follows:</p>

  <pre>
  .entry label1 [, label2]...
  </pre>

  <h3><code>.extern</code> Directive</h3>

  <p>This directive defines a <em>label</em> as <strong>external</strong> and is used to enter an external label defined in another file. The format is as follows:</p>

  <pre>
  .extern label1 [, label2]...
  </pre>

  <h2>Assembler Output</h2>

  <p>The assembler generates three output files:</p>

  <ol>
    <li><code>.ob</code> - Object file: Contains the machine code instructions and data.</li>
    <li><code>.ent</code> - Entries file: Contains the names and addresses of labels defined as entries.</li>
    <li><code>.ext</code> - Externals file: Contains the names and addresses of labels defined as externals.</li>
  </ol>

  <h2>Conclusion</h2>

  <p>The  Assembler project demonstrates the process of assembling assembly language programs into machine code instructions. It is a simplified model using imaginary hardware and assembly language, but it provides insights into the fundamental principles and techniques used in real assemblers.</p>
  <h1>.obj File - Base 10 Address and Base 2 Code</h1>
  <table>
   
  <tr>
    <th>Base 10 address</th>
    <th>Base 2 code</th>
    <th>Base for prodject</th>
    
 <table>
  <tr>
    <th>Base 10 address</th>
    <th>Base 2 code</th>
    <th>Additional code</th>
  </tr>
  <tr>
    <td>0100</td>
    <td>00000000110100</td>
    <td>........//./..</td>
  </tr>
  <tr>
    <td>0101</td>
    <td>00001100000000</td>
    <td>....//........</td>
  </tr>
  <tr>
    <td>0102</td>
    <td>00001000001010</td>
    <td>...../....././.</td>
  </tr>
  <tr>
    <td>0103</td>
    <td>00111001001000</td>
    <td>..///../../...</td>
  </tr>
  <tr>
    <td>0104</td>
    <td>00000111010010</td>
    <td>.....///./../.</td>
  </tr>
  <tr>
    <td>0105</td>
    <td>11111111111100</td>
    <td>////////////..</td>
  </tr>
  <tr>
    <td>0106</td>
    <td>00000000011000</td>
    <td>........//./.</td>
  </tr>
  <tr>
    <td>0107</td>
    <td>00001100000000</td>
    <td>....//........</td>
  </tr>
  <tr>
    <td>0108</td>
    <td>11111111101100</td>
    <td>/////////.//..</td>
  </tr>
  <tr>
    <td>0109</td>
    <td>11111010001000</td>
    <td>/////./.../...</td>
  </tr>
  <tr>
    <td>0110</td>
    <td>00000110011110</td>
    <td>............./</td>
  </tr>
  <tr>
    <td>0111</td>
    <td>00010000010100</td>
    <td>.../....././..</td>
  </tr>
  <tr>
    <td>0112</td>
    <td>00000011111100</td>
    <td>......//////..</td>
  </tr>
  <tr>
    <td>0113</td>
    <td>00000100010000</td>
    <td>...../.../....</td>
  </tr>
  <tr>
    <td>0114</td>
    <td>00001010000100</td>
    <td>...././..../..</td>
  </tr>
  <tr>
    <td>0115</td>
    <td>00000111101010</td>
    <td>............./</td>
  </tr>
  <tr>
    <td>0116</td>
    <td>00000111000100</td>
    <td>.....///.../..</td>
  </tr>
  <tr>
    <td>0117</td>
    <td>00001000010110</td>
    <td>..../...././/.</td>
  </tr>
  <tr>
    <td>0118</td>
    <td>01011010001000</td>
    <td>././/./.../...</td>
  </tr>
  <tr>
    <td>0119</td>
    <td>00000110011110</td>
    <td>.....//..////.</td>
  </tr>
  <tr>
    <td>0120</td>
    <td>00001000010110</td>
    <td>..../...././/.</td>
  </tr>
  <tr>
    <td>0121</td>
    <td>00000111101110</td>
    <td>............./</td>
  </tr>
  <tr>
    <td>0122</td>
    <td>00001111000000</td>
    <td>....////......</td>
  </tr>
  <tr>
    <td>0123</td>
    <td>00000001100001</td>
    <td>.......//..../</td>
  </tr>
  <tr>
    <td>0124</td>
    <td>00000001100010</td>
    <td>.......//.../.</td>
  </tr>
  <tr>
    <td>0125</td>
    <td>00000001100011</td>
    <td>.......//...//</td>
  </tr>
  <tr>
    <td>0126</td>
    <td>00000001100100</td>
    <td>.......//../..</td>
  </tr>
  <tr>
    <td>0127</td>
    <td>00000001100101</td>
    <td>.......//.././</td>
  </tr>
  <tr>
    <td>0128</td>
    <td>00000001100110</td>
    <td>.......//..//.</td>
  </tr>
  <tr>
    <td>0129</td>
    <td>00000000000000</td>
    <td>..............</td>
  </tr>
  <tr>
    <td>0130</td>
    <td>00000000000110</td>
    <td>...........//.</td>
  </tr>
  <tr>
    <td>0131</td>
    <td>11111111110111</td>
    <td>//////////.///</td>
  </tr>
  <tr>
    <td>0132</td>
    <td>00000000001111</td>
    <td>..........////</td>
  </tr>
  <tr>
    <td>0133</td>
    <td>00000000010110</td>
    <td>........././/.</td>
  </tr>
</table>
      
  <table>
  <tr>
    <th>Symbol</th>
    <th>Value</th>
  </tr>
  <tr>
    <td>LOOP</td>
    <td>103</td>
  </tr>
  <tr>
    <td>LENGTH</td>
    <td>130</td>
  </tr>
</table>

</body>
</html>

  

 


