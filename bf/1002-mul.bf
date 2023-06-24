,[>,]                 Read the first digit (ASCII value)
- 48                  Convert ASCII value to actual digit value

>,[>,]               Read the second digit (ASCII value)
- 48                  Convert ASCII value to actual digit value

[                      Start the multiplication loop
    <                      Move back to the first digit
    [->>+<<]              Copy the first digit to the second cell
    >                      Move to the second digit
    [->>>>+<<<<]          Copy the second digit to the fourth cell
    >-                     Decrement the second digit
    <<<<[-                  If the second digit is zero, exit the loop
        +>>>+<<            Multiply the first digit by the second digit
        [->-<]              Move the product back to the first cell
        >-                   Decrement the second digit
        <                   Move back to the first digit
    ]
    >>>>>>                 Move to the result cell
]

[<+>-]               Move the result back to the first cell

.+ 48                   Print the result (ASCII value)

