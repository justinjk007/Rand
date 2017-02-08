class Sort(object):

    def __init__(self, unsortedData=[]):
        self.data = unsortedData

    def insertionSort(self):
        print "Sorting started"
        global counter
        global swap
        counter = 0
        swap = 0
        size = len(self.data)
        for i in range(0, size):
            CurrentItem = self.data[i]
            # j is the divider of the sorted and unsorted portion
            j = i-1
            print j
            while j >= 0 and self.data[j] > CurrentItem:
                counter += 1
                self.data[j+1] = self.data[j]  # Swap happens here.
                swap += 1
                j = j-1  # incrementing the divider because we swapped values
            self.data[j+1] = CurrentItem
        return self.data  # Method ends here
# Class ends here


# def tester -> Tests the above code
print "Testing started"
unsorted = [547, 547, 547, 546, 545, 87, 54, 6, 5, 5, 0, -1, -78, -87]
obj = Sort(unsorted)
sortedData = obj.insertionSort()
print ("Lenth of the array is: "+str(len(sortedData)))
print ("Number of comaprisons: "+str(counter))
print ("Number of swaps: "+str(swap))
for val in sortedData:
    print (str(val) + ","),
# The comma on the end of the line 26 makes the printing at the same line.
print "\nTesting completed"
