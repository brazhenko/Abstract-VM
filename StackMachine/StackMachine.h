//
// Created by 17641238 on 25.03.2020.
//

#ifndef AVM_STACKMACHINE_H
#define AVM_STACKMACHINE_H

#include <stack>
#include <deque>
#include <vector>
#include "IOperand.h"
#include "Instruction.h"

class StackMachine
{
private:
	StackMachine() = default;
	StackMachine(const StackMachine&);
	~StackMachine() = default;

	StackMachine& operator=(StackMachine&);

	std::vector<const IOperand*> stack_;
	std::vector<Instruction> instructions_;

	// Current operation iterator
	std::vector<Instruction>::iterator op;

	void Push(const IOperand *operand);
	void Pop();
	void Dump() const;
	void Assert(const IOperand *op);
	void Add();
	void Sub();
	void Mul();
	void Div();
	void Mod();
	void Print() const;
public:
	static StackMachine& Instance();
	void AddInstruction(Instruction);
	std::vector<Instruction>::iterator getCurrentOperation();
	void Execute();
};


#endif //AVM_STACKMACHINE_H
