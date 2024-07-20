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
  - `vector<int> memory:` Represents the memory unit of the simulator.
  - `int registers[NUM_REGISTERS]:` An array representing the registers.
  - `int pc:` Program counter, keeps track of the current instruction address.
- **Public Methods**
  - `ISA_Simulator()`: Constructor that initializes the memory and registers by calling the reset() function.
  - `void reset()`: Resets the memory and registers to their initial states.
  - `void execute(const vector<Instruction>& program)`: Takes a vector of instructions and executes them. Each instruction is processed based on its opcode.
  - `void displayState() const`: Displays the current state of the memory and registers in a formatted manner.

