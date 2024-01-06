a = []
n = int(input("Enter the total students who attended the training program:- "))
print("Enter the roll no. of students who attended the training program below:- ")
for i in range(n):
    a.append(int(input()))

b = int(input("Enter the roll no. that you want to search: "))

#--------------------------------------------------------------------------------------

def linear_search(a, b):
    for i in a:
        if i == b:
            return 1

    return -1

#--------------------------------------------------------------------------------------

def sentinel_search(a, b, n):
    
    last = a[n - 1]                    # Last element of the array
    a[n - 1] = b                       # Element to be searched is
    i = 0                              # placed at the last index
    
    while (a[i] != b):
        i += 1

    a[n - 1] = last                      # Put the last element back

    if ((i < n - 1) or (b == a[n - 1])):
        return 1
    else:
        return -1

#----------------------------------------------------------------------------------------

print("1) Linear search")
print("2) Sentinal search")
ch = int(input("Enter your choice "))

if ch == 1:
    result = linear_search(a, b)
    if result == -1:
        print("The entered roll no. did not attend the training program.")
    else:
        print("The entered roll no. has attended the training program.")

elif ch == 2:
    result = sentinel_search(a, b, n)
    if result == -1:
        print("The entered roll no. did not attend the training program.")
    else:
        print("The entered roll no. has attended the training program.")

else:
    print("Entered Wrong Choice")
