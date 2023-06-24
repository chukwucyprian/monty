,>,                  Read the first digit and store it in cell 0 and cell 1
[                     Start multiplication loop
    -                  Decrement cell 0 to convert ASCII to digit value
    <                  Move to cell 1
    -                  Decrement cell 1 to convert ASCII to digit value
    >                  Move to cell 0
    [->+>+<<]          Multiply the two digits and store the result in cell 0 and cell 2
    >-                 Decrement cell 1
    <                  Move to cell 2
]
<.                    Print the result (digit value)
+ 48                  Convert the result to ASCII value
.                     Print the result (ASCII value)

