def score():
    avg = 0
    absent = 0
    present_student = []
    for i in student_list:
        if i == "A":
            absent += 1
        else:
            avg += int(i)
            present_student.append(int(i))

    avg_new = avg / len(present_student)  # the average of the class
    max_marks = present_student[0]  # max_marks
    min_marks = present_student[0]  # min_marks
    max_freq = 0
    for i in present_student:
        if i > max_marks:
            max_marks = i
        if i < min_marks:
            min_marks = i
        freq = present_student.count(i)
        if freq > max_freq:
            max_freq = freq
            max_freq_marks = i

    return avg_new, absent, max_marks, min_marks, max_freq_marks

#------------------------------------------------------------------------------------
n = int(input("Enter the no. of students in class : "))
student_list = []
print("Enter the marks of students in Fundamental of Data Structure : ")
print('''Type "A" if the student is absent''')
for i in range(n):
    marks =input()
    student_list.append(marks)
print(marks)

result = score()

print("The average score of class is : {}".format(result[0]))
print("The Highest score of class is : {}".format(result[2]))
print("The lowest score of class is : {}".format(result[3]))
print("Count of students who were absent for the test : {}".format(result[1]))
print("The mark with highest frequency of class is : {}".format(result[4]))