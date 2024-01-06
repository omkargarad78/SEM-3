def fe_data():
    arr = []
    n = int(input("Enter Number of Students :- "))
    print("\nEnter the Percentage of Students :- ")
    for i in range(n):
        x = float(input())
        arr.append(x)

    return arr,n
#------------------------------------------------------------------------------------------

def sel_sort(to_sort_arr,cnt):   
    for j in range(cnt):
        min_idx = j

        for i in range(j + 1, cnt):
            if to_sort_arr[i] < to_sort_arr[min_idx]:
                min_idx = i
         
        (to_sort_arr[j], to_sort_arr[min_idx]) = (to_sort_arr[min_idx], to_sort_arr[j])
    return to_sort_arr
#-------------------------------------------------------------------------------------------

def bubbleSort(to_bub_sort,cnt):
    for i in range(cnt):
        for j in range(0, cnt - i - 1):
            if to_bub_sort[j] > to_bub_sort[j + 1]:             #greater than

                temp = to_bub_sort[j]
                to_bub_sort[j] = to_bub_sort[j+1]               #is equal to
                to_bub_sort[j+1] = temp
    
    return to_bub_sort
#-------------------------------------------------------------------------------------------
fe_percent,cnt = fe_data()
#-------------------------------------------------------------------------------------------
ch = 'y'
while(ch=='y' or ch == "Y"):
    opt = int(input("\nWhat would you like to perform?\n\t1.Display the array\n\t2.Sort the array."
    "\n\t3.Display TOP five Scores.\nt5.Exit current program. :- "))

    if opt==1:
        print("\nStudent Database of Percentage's :- ")
        print(fe_percent)

    elif opt==2:
        choice = int(input("\nHow would you like to sort the inserted array?\n\t1.Selection Sort Method\n\t2.Bubble Sort :- "))
        
        if choice == 1:
            print("The Array is Sorted Using Selection Sort Method :- \n\t",sel_sort(fe_percent,cnt))
        elif choice == 2:
            print("The Array is Sorted Using Selection Sort Method :- \n\t",bubbleSort(fe_percent,cnt))
        else:
            print("Enter Correct Option .")

    elif opt == 3:
        selection_sort = sel_sort(fe_percent,cnt)
        selection_sort.reverse()
        print("\nTOP FIVE Percentages in First Year Engineering :-",selection_sort[0:5])

    elif opt==5:
        print("Program Terminated")

    else:
        print("Enter Correct Option.")
    
    print("\nDo you want to run this program again?(y/n)")
    ch = input("\t - ")