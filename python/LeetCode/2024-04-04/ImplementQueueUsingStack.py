from typing import *


class MyQueue:

    def __init__(self):
        self.stack: List[int] = []

    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        buffer: List[int] = [self.stack.pop() for _ in range(len(self.stack) - 1)]
        x = self.stack.pop()
        while buffer:
            self.stack.append(buffer.pop())
        return x

    def peek(self) -> int:
        return self.stack[0]

    def empty(self) -> bool:
        return not self.stack
