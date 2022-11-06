grade = input()
gpa = 0.0
if grade != "F":
    ch = grade[0]
    if ch == "A":
        gpa = 4.0
    elif ch == "B":
        gpa = 3.0
    elif ch == "C":
        gpa = 2.0
    elif ch == "D":
        gpa = 1.0
    ch = grade[1]
    if ch == "+":
        gpa += 0.3
    elif ch == "-":
        gpa -= 0.3
print(gpa)
