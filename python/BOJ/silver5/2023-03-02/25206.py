import sys

gpa, totCredit = 0, 0
grades = {
    "A+": 4.5,
    "A0": 4.0,
    "B+": 3.5,
    "B0": 3.0,
    "C+": 2.5,
    "C0": 2.0,
    "D+": 1.5,
    "D0": 1.0,
    "F": 0,
}
for line in sys.stdin.readlines():
    name, credit, rating = line.split()
    credit = float(credit)
    if rating == "P":
        continue
    totCredit += credit
    gpa += grades[rating] * credit
gpa /= totCredit
print(gpa)
