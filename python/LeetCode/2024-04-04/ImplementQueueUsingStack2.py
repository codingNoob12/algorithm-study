from typing import *


class MyQueue:

    def __init__(self):
        self.input: List[int] = []
        self.output: List[int] = []

    def push(self, x: int) -> None:
        self.input.append(x)

    def pop(self) -> int:
        if not self.output:
            self.move_elements_to_output_stack()
        return self.output.pop()

    def peek(self) -> int:
        if not self.output:
            self.move_elements_to_output_stack()
        return self.output[-1]

    def empty(self) -> bool:
        return not self.input and not self.output

    def move_elements_to_output_stack(self):
        while self.input:
            self.output.append(self.input.pop())
