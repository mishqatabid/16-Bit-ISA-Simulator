#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Define the size of memory and number of registers
const int MEMORY_SIZE = 256;
const int NUM_REGISTERS = 8;

// Instruction set opcodes
enum Opcode {
    ADD = 0,
    SUB = 1,
    LOAD = 2,
    STORE = 3,
    END = 4 // New end instruction
};

// Define an instruction structure
struct Instruction {
    Opcode opcode;
    int operand1;
    int operand2;
};

class ISA_Simulator {
private:
    vector<int> memory; // Memory unit
    int registers[NUM_REGISTERS]; // Registers
    int pc; // Program counter

public:
    ISA_Simulator() {
        memory.resize(MEMORY_SIZE);
        reset();
    }

    // Initialize memory and registers
    void reset() {
        fill(memory.begin(), memory.end(), 0);
        fill(registers, registers + NUM_REGISTERS, 0);
        pc = 0;
    }

    // Execute the instructions
    void execute(const vector<Instruction>& program) {
        for (const auto& instr : program) {
            if (instr.opcode == STORE) {
                memory[instr.operand2] = instr.operand1; // Store the value in memory
            }
            else if (instr.opcode == LOAD) {
                registers[instr.operand2] = memory[instr.operand2]; // Load the value in registers from memory
            }
            else if (instr.opcode == ADD) {
                registers[instr.operand1] += registers[instr.operand2]; // Add the value in register
            }
            else if (instr.opcode == SUB) {
                registers[instr.operand1] -= registers[instr.operand2]; // Subtract the value in register
            }
            else if (instr.opcode == END) {
                return;
            }
		}
		
    }

    // Display state of registers and memory
    void displayState() const {
        cout << "Memory:" << endl;
        for (size_t i = 0; i < memory.size(); ++i) {
            cout << hex << setw(4) << setfill('0') << memory[i] << " ";
            if ((i + 1) % 8 == 0)
                cout << endl;
        }
        cout << "\nRegisters:" << endl;
        for (size_t i = 0; i < 8; ++i) {
            cout << "R" << i << ": " << hex << setw(4) << setfill('0') << registers[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    ISA_Simulator simulator;

    vector<Instruction> program = {
        {STORE, 5, 1}, // Store value 10 into memory location 1
        {STORE, 55, 2}, // Store value 20 into memory location 2
        {LOAD, 0, 1},   // Load value from memory location 1 into register 0
        {LOAD, 1, 2},   // Load value from memory location 2 into register 1
        {SUB, 0, 1},    // Add values in register 0 and 1, store result in register 0
        {END, 0, 0}     // End the program
    };

    
    simulator.execute(program);
	simulator.displayState(); // Display memory and registers only once at the end

    return 0;
}

