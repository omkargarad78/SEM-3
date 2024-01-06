students_attend = []
n=int(input("Enter the total students who attended the training program. "))
print("Enter the roll no. of students who attended the training program. ")
for i in range(n):
    students_attend.append(int(input()))

search_element = int(input("Enter the roll no. that you want to search : "))

students_attend.sort()      #sorting the elemnts in the list
start = 0
#----------------------------------------------------------------------------------------------

def binary_search(students_attend,search_element,start,n):

    if start > n:
        return -1

    mid = (start+n)//2

    if search_element == students_attend[mid]:
        return mid

    if search_element < students_attend[mid]:
        return binary_search(students_attend,search_element,start,mid-1)
    else:
        return binary_search(students_attend,search_element,mid+1,n)
#----------------------------------------------------------------------------------------------

def fibonacci_search(students_attend, search_element, n):
    a = 0
    b = 1
    fibM = a + b

    while (fibM < n):
        a = b
        b = fibM
        fibM = a + b

    offset = -1

    while (fibM > 1):

        i = min(offset+a, n-1)

        if (students_attend[i] < search_element):
            fibM = b
            b = a
            a = fibM - b
            offset = i

        elif (students_attend[i] > search_element):
            fibM = a
            b = b - a
            a = fibM - b

        else :
            return i

    if(b and students_attend[offset+1] == search_element):
        return offset+1

    else:
        return -1
#-------------------------------------------------------------------------------------------

print("1) Binary search")
print("2) Fibonacci search")
ch = int(input("Enter your choice "))

if ch == 1:
    result = binary_search(students_attend,search_element,start,n)
    if result == -1 :
        print("The entered roll no. did not attend the training program.")
    else:
        print("The entered roll no. has attended the training program.")

elif ch == 2:
    result = fibonacci_search(students_attend, search_element, n)
    if result == -1 :
        print("The entered roll no. did not attend the training program.")
    else:
        print("The entered roll no. has attended the training program.")

else:
    print("Entered Wrong Choice")