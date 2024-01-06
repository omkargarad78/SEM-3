def add():
    a = []
    print("Enter the dimensions of the matrix.")
    a_row = int(input("Enter the no. of rows : "))
    a_column = int(input("Enter the no. of columns : "))

    for i in range(a_row):
        print("\n")
        b = []
        for j in range(a_column):
            x = int(input("Enter a value :"))
            b.append(x)
        a.append(b)

    for i in range(a_row):
        for j in range(a_column):
            print(a[i][j], end=" ")
        print()

    c = []
    print("Enter the dimensions of the matrix.")
    c_row = int(input("Enter the no. of rows : "))
    c_column = int(input("Enter the no. of columns : "))

    for i in range(c_row):
        print("\n")
        d = []
        for j in range(c_column):
            x = int(input("Enter a value :"))
            d.append(x)
        c.append(d)

    for i in range(c_row):
        for j in range(c_column):
            print(c[i][j], end=" ")
        print()

    res = [[0, 0], [0, 0]]

    print("\n The sum of two matrices is:")
    for i in range(c_row):
        for j in range(c_column):
            res[i][j] = a[i][j] + c[i][j]
            print(res[i][j], end=" ")
        print()

#-----------------------------------------------------------------------------
def sub():
    a = []
    print("Enter the dimensions of the matrix.")
    a_row = int(input("Enter the no. of rows : "))
    a_column = int(input("Enter the no. of columns : "))

    for i in range(a_row):
        print("\n")
        b = []
        for j in range(a_column):
            x = int(input("Enter a value :"))
            b.append(x)
        a.append(b)

    for i in range(a_row):
        for j in range(a_column):
            print(a[i][j], end=" ")
        print()

    c = []
    print("Enter the dimensions of the matrix.")
    c_row = int(input("Enter the no. of rows : "))
    c_column = int(input("Enter the no. of columns : "))

    for i in range(c_row):
        print("\n")
        d = []
        for j in range(c_column):
            x = int(input("Enter a value :"))
            d.append(x)
        c.append(d)

    for i in range(c_row):
        for j in range(c_column):
            print(c[i][j], end=" ")
        print()

    res = [[0, 0], [0, 0]]

    print("\n The subtraction of two matrices is:")
    for i in range(c_row):
        for j in range(c_column):
            res[i][j] = a[i][j] - c[i][j]
            print(res[i][j], end=" ")
        print()

#-----------------------------------------------------------------------------
def multiply():
    a = []
    print("Enter the dimensions of the 1st  matrix.")
    a_row = int(input("Enter the no. of rows : "))
    a_column = int(input("Enter the no. of columns : "))

    c = []
    print("Enter the dimensions of the 2nd matrix.")
    c_row = int(input("Enter the no. of rows : "))
    c_column = int(input("Enter the no. of columns : "))
#-------------------------------------------
    res = []
    if (a_column == c_row):
        print("Enter the 1st matrix")
        for i in range(a_row):
            print("\n")
            b = []
            for j in range(a_column):
                x = int(input("Enter a value :"))
                b.append(x)
            a.append(b)

        for i in range(a_row):
            for j in range(a_column):
                print(a[i][j], end=" ")
            print()

        print("Enter the 2nd matrix")
        for i in range(c_row):
            print("\n")
            d = []
            for j in range(c_column):
                x = int(input("Enter a value :"))
                d.append(x)
            c.append(d)

        print(end=" ")
        for i in range(c_row):
            for j in range(c_column):
                print(c[i][j], end=" ")
            print()

        for i in range(a_row):                          #taking the order of matrix multiplication from the user
            temp = []
            for j in range(c_row):
                temp.append(0)
            res.append(temp)

        for i in range(len(a)):                         #multiplying the matrices
            for j in range(len(c[0])):
                for k in range(len(c)):
                    res[i][j] += a[i][k] * c[k][j]

        for i in range(a_row):                          #printing the multiplied matrix
            for j in range(c_column):
                print(res[i][j], end=" ")
            print()


    else:

        print("Matrix multiplication not possible.")

#-----------------------------------------------------------------------------------
def transpose():
    a = []
    print("Enter the dimensions of the matrix.")
    a_row = int(input("Enter the no. of rows : "))
    a_column = int(input("Enter the no. of columns : "))

    for i in range(a_row):
        print("\n")
        b = []
        for j in range(a_column):
            x = int(input("Enter a value :"))
            b.append(x)
        a.append(b)

    print("Original martrix is:",end=" ")
    for i in range(a_row):
        for j in range(a_column):
            print(a[i][j], end=" ")
        print()

    print("Transpose of the entered matrix is : ", end=" ")
    for i in range(a_row):
        for j in range(a_column):
            print(a[j][i], end=" ")                             #just interchanging the values of the i and j
        print()
#-----------------------------------------------------------------------------

print("For Addition")
add()
print("For Subtraction")
sub()
print("For Multiplication")
multiply()
print("For Transpose")
transpose()
