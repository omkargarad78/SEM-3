cricket = []
football = []
badminton = []
total_student_list = []
#---------------------------------------------------------------------------

total = int(input("Enter the total no. of students in the class: ", ))
print("Enter the roll no. of students in the class. ")
for i in range(total):
    temp = int(input())
    total_student_list.append(temp)

#-------------------------------------------------------------------------------

c = int(input("Enter the total no. of students playing cricket: "))
print("Enter the roll no. of students playing cricket. ")
for i in range(c):
    temp = int(input())
    cricket.append(temp)
print(cricket)

b = int(input("Enter the total no. of students playing badminton: "))
print("Enter the roll no. of students playing badminton. ")
for i in range(b):
    temp = int(input())
    badminton.append(temp)
print(badminton)

f = int(input("Enter the total no. of students playing football: "))
print("Enter the roll no. of students playing football. ")
for i in range(f):
    temp = int(input())
    football.append(temp)
print(football)

#------------------------------------------------------------------------------------
# bit a
def play_c_n_b():
    c_n_b_list = []
    for i in range(c):
        for j in range(b):
            if cricket[i] == badminton[j]:
                c_n_b_list.append(cricket[i])

    return c_n_b_list

# bit b
def play_c_or_b():
    temp_list = cricket + badminton
    c_n_b_std = play_c_n_b()
    play_c_or_b_list = []
    for i in temp_list:
        if i in c_n_b_std:
            continue
        else:
            play_c_or_b_list.append(i)

    return play_c_or_b_list

# bit c
def play_neither_c_nor_b():
    neither_c_nor_b_list = []

    total= cricket + badminton + football

    play_c_or_b_list = play_c_or_b()
    play_c_n_b_list = play_c_n_b()

    for i in total:
        if i in play_c_or_b_list or i in play_c_n_b_list:
            continue
        else:
            neither_c_nor_b_list.append(i)

    return len(neither_c_nor_b_list)


# bit d
def c_n_f_not_b():
    c_n_f_list = []
    temp = []
    for i in range(c):
        for j in range(f):
            if cricket[i] == football[j]:
                temp.append(cricket[i])

    for i in temp:
        if i in badminton:
            continue
        else:
            c_n_f_list.append(i)

    return len(c_n_f_list)

#-------------------------------------------------------------------------------------

bit_a = play_c_n_b()
print("List of students who play both cricket and badmintion is : ", bit_a)

bit_b = play_c_or_b()
print("List of students who play either cricket or badmintion but not both is : ", bit_b)

bit_c = play_neither_c_nor_b()
print("Number of students who play neither cricket nor badminton : ", bit_c)

bit_d = c_n_f_not_b()
print("Number of students who play both cricket and football but not badminton. ", bit_d)

#---------------------------------------------------------------------------------------
