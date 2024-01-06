def partition(arr, low, high):
    i = (low - 1)                   # index of smaller element initially -1
    pivot = arr[high]                # pivot

    for j in range(low, high):
        if arr[j] < pivot:              # If current element is smaller than the pivot
            i = i + 1                   # increment index of smaller element

            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)
    
#--------------------------------------------------------------------------------------
def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)  # pi is partitioning index, arr[p] is now at right place
                                                        
        quick_sort(arr, low, pi - 1)    # Separately sort elements before # partition and after partition            
                                                        

#---------------------------------------------------------------------------------------
marks = []
n = int(input("Enter the total no. of students in the class : "))
print("Enter the percentage of roll no.in First Year :")
for i in range(n):
    temp = input()
    marks.append(temp)

print("First Year Percentage")
for i in marks:
    print(i)                #printing marks

n = len(marks)
quick_sort(marks, 0, n - 1)

#---------------------------------------------------------------------------------------
marks.sort()
print("List in sorted order is : ")
for i in marks:
    print(i)

marks.reverse()
print("Top 5 scorer are : ")
for i in range(5):
    print(marks[i])

#----------------------------------------------------------------------------------------
