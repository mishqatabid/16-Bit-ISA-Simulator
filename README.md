# 16 Bit Intruction Set Architecture (ISA) Simulator
The ISA Simulator is a simple emulator for a hypothetical Instruction Set Architecture (ISA). It simulates basic operations such as addition, subtraction, loading values from memory into registers, and storing values from registers into memory. The simulator also includes an "END" instruction to terminate the execution.

## Features
- **Memory Management:** Simulates a memory unit of fixed size.
- **Registers:** Includes a set of general-purpose registers.
- **Instruction Execution:** Executes a set of predefined instructions.
- **Program Counter:** Maintains the current instruction address.
- **State Display:** Displays the state of memory and registers after execution.

## `ISA_Simulator` Class
This is the core class of the simulator. It manages memory, registers, and the execution of instructions.
- **Private Members**
  - `vector<int> memory`: Represents the memory unit of the simulator.
  - `int registers[NUM_REGISTERS]`: An array representing the registers.
  - `int pc`: Program counter, keeps track of the current instruction address.
- **Public Methods**
  - `ISA_Simulator()`: Constructor that initializes the memory and registers by calling the reset() function.
  - `void reset()`: Resets the memory and registers to their initial states.
  - `void execute(const vector<Instruction>& program)`: Takes a vector of instructions and executes them. Each instruction is processed based on its opcode.
  - `void displayState() const`: Displays the current state of the memory and registers in a formatted manner.

## `Instruction` Struct
This structure defines the format of an instruction. It includes an opcode and two operands.
- `Opcode opcode`: The operation code defining the type of operation (ADD, SUB, LOAD, STORE, END).
- `int operand1`: The first operand for the instruction.
- `int operand2`: The second operand for the instruction.

## `Opcode` Enum
Defines the set of operation codes supported by the simulator.
- `ADD = 0`: Adds the values in two registers.
- `SUB = 1`: Subtracts the value in one register from another.
- `LOAD = 2`: Loads a value from memory into a register.
- `STORE = 3`: Stores a value from a register into memory.
- `END = 4`: Terminates the execution of the program.

## Sample Program
The sample program defines a series of instructions for the ISA Simulator to execute. It starts by storing the value `5` into memory location `1` and `55` into memory location `2`. Next, it loads the value from memory location `1` into register `0` and the value from memory location `2` into register `1`. Then, it performs a subtraction operation where the value in register `1` is subtracted from the value in register `2`, and the result is stored back in register `2`. Finally, the `END` instruction terminates the execution of the program. This sequence demonstrates the basic operations of storing values in memory, loading values into registers, performing arithmetic operations on the registers, and concluding the program execution.

### Code Snippet
```
vector<Instruction> program = {
    {STORE, 5, 1},  // Store value 5 into memory location 1
    {STORE, 55, 2}, // Store value 55 into memory location 2
    {LOAD, 0, 1},   // Load value from memory location 1 into register 0
    {LOAD, 1, 2},   // Load value from memory location 2 into register 1
    {SUB, 2, 1},    // Subtract value in register 1 from register 2, store result in register 2
    {END, 0, 0}     // End the program
};
```

### Execution
The program is executed by calling the execute method with the defined instructions:
```
simulator.execute(program);
```
### Display State
After execution, the state of memory and registers is displayed using the displayState method:
```
simulator.displayState();
```
### Example Output
The output will show the contents of the memory and registers after the program has executed. The values are displayed in hexadecimal format with zero padding.
```console
Memory:
0000 0005 0037 0000 0000 0000 0000 0000
0000 0000 0000 0000 0000 0000 0000 0000
...

Registers:
R1: 0005
R2: 0032
R3: 0000
R4: 0000
R5: 0000
R6: 0000
R7: 0000
R8: 0000
```
