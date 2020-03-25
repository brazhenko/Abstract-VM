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

	std::vector<IOperand*> stack_;
	std::vector<Instruction> instructions_;

	void Push(IOperand *op);
	void Pop();
	void Dump() const;
	void Assert(const IOperand *op);
	void Add();
	void Sub();
	void Mul();
	void Div();
	void Mod();
	void Print() const;
	void Exit();

	bool started = false;
public:
	static StackMachine& Instance();
	void AddInstruction(Instruction);
	void Execute();

};


#endif //AVM_STACKMACHINE_H
